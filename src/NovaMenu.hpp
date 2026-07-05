#pragma once
#include <Geode/Geode.hpp>
#include <Geode/ui/Popup.hpp>

namespace nova {
    class NovaMenu : public geode::Popup<std::string const&> {
    protected:
        bool setup(std::string const& value) override;
        void onTabChanged(cocos2d::CCObject* sender);

        void createPlayerPage();
        void createCreatorPage();
        void createLevelPage();
        void createCosmeticPage();
        void createBotPage();

        void showTab(int index);

        cocos2d::CCNode* m_pages[5] = {nullptr};
        int m_currentTab = 0;

    public:
        static NovaMenu* create(std::string const& title);
    };
}
