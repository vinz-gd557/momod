#pragma once
#include <Geode/Geode.hpp>

namespace nova {
    class FloatingButton : public cocos2d::CCMenu {
    private:
        bool m_isDragging = false;
        cocos2d::CCPoint m_touchOffset;
        cocos2d::CCPoint m_startPosition;

        bool init() override;
    public:
        static FloatingButton* create();
        
        bool ccTouchBegan(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;
        void ccTouchMoved(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;
        void ccTouchEnded(cocos2d::CCTouch* touch, cocos2d::CCEvent* event) override;
        
        void onBtnClick(cocos2d::CCObject* sender);
    };
}
