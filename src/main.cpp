#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>
#include "FloatingButton.hpp"

using namespace geode::prelude;

class $modify(MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto btn = nova::FloatingButton::create();
        this->addChild(btn, 100);

        return true;
    }
};
