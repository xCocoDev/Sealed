//
// Created by xCocoDev on 27/12/18.
//

#include "SceneManager.h"
#include "Engine.h"
#include "Receiver.h"

namespace en {

    void SceneManager::update(float dt) {

        if (m_openNextUpdateScene)
            setCurrentScene(std::move(m_openNextUpdateScene));

        if (m_currentScene)
            m_currentScene->update(dt);
    }

    void SceneManager::setCurrentScene(std::unique_ptr<en::Scene> scene) {

        closeCurrentScene();

        m_currentScene = std::move(scene);
        if (m_currentScene) {
            m_currentScene->setEngine(*m_engine);
            m_currentScene->open();
            Receiver<OnSceneOpened>::broadcast({this});
        }
    }

    void SceneManager::closeCurrentScene() {

        if (!m_currentScene)
            return;

        m_currentScene->close();
        m_engine->getRegistry().destroyAll();
        Receiver<OnSceneClosed>::broadcast({this});
    }

    void SceneManager::setCurrentSceneNextUpdate(std::unique_ptr<Scene> scene) {

        m_openNextUpdateScene = std::move(scene);
    }
}