#include "NovaMenu.hpp"
#include <vector>

using namespace nova;
using namespace geode::prelude;

namespace {
    constexpr float kPopupWidth = 420.f;
    constexpr float kPopupHeight = 280.f;

    CCMenuItemSpriteExtra* makeTabBtn(std::string const& text, CCObject* target, int tabIndex) {
        auto sprite = ButtonSprite::create(text.c_str(), 50, true, "bigFont.fnt", "GJ_button_02.png", 25.f, 0.4f);
        auto btn = CCMenuItemSpriteExtra::create(sprite, target, menu_selector(NovaMenu::onTabChanged));
        btn->setTag(tabIndex);
        return btn;
    }
    
    CCLabelBMFont* makeLabel(std::string const& text, CCPoint pos, CCNode* parent) {
        auto label = CCLabelBMFont::create(text.c_str(), "bigFont.fnt");
        label->setScale(0.45f);
        label->setPosition(pos);
        parent->addChild(label);
        return label;
    }
}

NovaMenu* NovaMenu::create(std::string const& title) {
    auto ret = new NovaMenu();
    if (ret && ret->initAnchored(kPopupWidth, kPopupHeight, title)) {
        ret->autorelease();
        return ret;
    }
    CC_SAFE_DELETE(ret);
    return nullptr;
}

bool NovaMenu::setup(std::string const& value) {
    this->setTitle("NovaClient Mega Menu");

    auto tabMenu = CCMenu::create();
    tabMenu->setPosition({55.f, kPopupHeight / 2.f - 10.f});
    
    std::vector<std::string> tabNames = {"Player", "Creator", "Level", "Cosmetic", "Bot"};
    for (size_t i = 0; i < tabNames.size(); i++) {
        auto btn = makeTabBtn(tabNames[i], this, static_cast<int>(i));
        btn->setPosition({0.f, 80.f - (static_cast<float>(i) * 35.f)});
        tabMenu->addChild(btn);
    }
    m_mainLayer->addChild(tabMenu);

    for (int i = 0; i < 5; i++) {
        m_pages[i] = CCNode::create();
        m_pages[i]->setPosition({120.f, 0.f});
        m_mainLayer->addChild(m_pages[i]);
    }

    createPlayerPage();
    createCreatorPage();
    createLevelPage();
    createCosmeticPage();
    createBotPage();

    showTab(0);
    return true;
}

void NovaMenu::showTab(int index) {
    m_currentTab = index;
    for (int i = 0; i < 5; i++) {
        if (m_pages[i]) m_pages[i]->setVisible(i == index);
    }
}

void NovaMenu::onTabChanged(CCObject* sender) {
    showTab(sender->getTag());
}

void NovaMenu::createPlayerPage() {
    makeLabel("--- Player Cheats ---", {150.f, 200.f}, m_pages[0]);
}

void NovaMenu::createCreatorPage() {
    makeLabel("--- Creator/Editor ---", {150.f, 200.f}, m_pages[1]);
}

void NovaMenu::createLevelPage() {
    makeLabel("--- Level Hacks ---", {150.f, 200.f}, m_pages[2]);
}

void NovaMenu::createCosmeticPage() {
    makeLabel("--- Cosmetics ---", {150.f, 200.f}, m_pages[3]);
}

void NovaMenu::createBotPage() {
    makeLabel("--- Bot Replay ---", {150.f, 200.f}, m_pages[4]);
}
