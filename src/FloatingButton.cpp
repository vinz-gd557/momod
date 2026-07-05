#include "FloatingButton.hpp"
#include "NovaMenu.hpp"

using namespace nova;
using namespace geode::prelude;

FloatingButton* FloatingButton::create() {
    auto ret = new FloatingButton();
    if (ret && ret->init()) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool FloatingButton::init() {
    if (!CCMenu::init()) return false;

    this->setTouchMode(cocos2d::kCCTouchOneByOne);
    this->setTouchEnabled(true);
    this->setTouchPriority(-500);

    auto sprite = CircleButtonSprite::createWithSpriteFrameName("GJ_plusBtn_001.png", 1.0f, CircleBaseColor::Green);
    sprite->setScale(0.65f);

    auto btn = CCMenuItemSpriteExtra::create(sprite, this, menu_selector(FloatingButton::onBtnClick));
    btn->setTag(1);
    btn->setPosition({0, 0});
    this->addChild(btn);

    auto winSize = CCDirector::sharedDirector()->getWinSize();
    this->setPosition({winSize.width - 40.f, winSize.height - 100.f});

    return true;
}

bool FloatingButton::ccTouchBegan(CCTouch* touch, CCEvent* event) {
    auto btn = this->getChildByTag(1);
    if (!btn) return false;

    auto touchPoint = touch->getLocation();
    auto localPoint = btn->convertToNodeSpace(touchPoint);
    auto rect = CCRect{0, 0, btn->getContentSize().width, btn->getContentSize().height};

    if (rect.containsPoint(localPoint)) {
        m_isDragging = false;
        m_startPosition = this->getPosition();
        m_touchOffset = this->getPosition() - touchPoint;
        return true;
    }
    return false;
}

void FloatingButton::ccTouchMoved(CCTouch* touch, CCEvent* event) {
    auto touchPoint = touch->getLocation();
    auto newPos = touchPoint + m_touchOffset;

    auto winSize = CCDirector::sharedDirector()->getWinSize();
    newPos.x = std::max(20.f, std::min(winSize.width - 20.f, newPos.x));
    newPos.y = std::max(20.f, std::min(winSize.height - 20.f, newPos.y));

    this->setPosition(newPos);

    if (m_startPosition.getDistanceSq(newPos) > 25.f) {
        m_isDragging = true;
    }
}

void FloatingButton::ccTouchEnded(CCTouch* touch, CCEvent* event) {
    if (!m_isDragging) {
        this->onBtnClick(nullptr);
    }
    m_isDragging = false;
}

void FloatingButton::onBtnClick(CCObject* sender) {
    if (auto menu = NovaMenu::create("NovaClient GD")) {
        menu->show();
    }
}
