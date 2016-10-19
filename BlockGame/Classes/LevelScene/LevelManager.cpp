//
//  LevelManager.cpp
//  BlockGame
//
//  Created by Coody on 2016/10/18.
//
//

#include "LevelManager.h"

// for Constant
#include "BlockGameConstant.h"

// for Actor
#include "TitleLabelActor.h"
#include "MenuActor.h"

USING_NS_CC;

LevelManager::LevelManager(){
    
}

LevelManager::~LevelManager(){
    
}

bool LevelManager::init(){
    if ( CCLayerColor::initWithColor(D_BlockGame_GreenColor) ) {
        
        // 建立 title
        this->initialTitle();
        
//        this->initialBackground();
//        
//        this->initialMenuButton();
//        
//        this->preloadSounds();
//        
//        this->playBGMusic();
        
        return true;
    }
    return false;
}

void LevelManager::initialTitle(){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // Title
    TitleLabelActor *labelActor = TitleLabelActor::createWithSetting(CCString::create("Select Level"),
                                                                     D_BlockGame_FontName,
                                                                     110,
                                                                     true,
                                                                     true);
    labelActor->setColor(ccWHITE);
    labelActor->setPosition(ccp(visibleSize.width*0.5, visibleSize.height*0.9));
    this->addChild(labelActor , EnumLevelManagerTag_TitleLabel , EnumLevelManagerTag_TitleLabel);
    labelActor->startFadeInAction( this , callfunc_selector(LevelManager::initialMenu) );
    
}

void LevelManager::initialMenu(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    {
        MenuActor *menu = MenuActor::createWithSetting(CCString::create("1 ~ 35 (Hard)"),
                                                       D_BlockGame_FontName,
                                                       76,
                                                       true,
                                                       this,
                                                       callfuncN_selector(LevelManager::pressedHardLevel));
//        menu->setOpacity(0.0f);
        menu->setPosition(ccp( visibleSize.width , visibleSize.height*0.67 ));
        this->addChild(menu , EnumLevelManagerTag_MenuHard , EnumLevelManagerTag_MenuHard);
        
        menu->startMoveInAction(0.1f);
    }
    
    {
        MenuActor *menu = MenuActor::createWithSetting(CCString::create("1 ~ 25  (Mid)"),
                                                       D_BlockGame_FontName,
                                                       76,
                                                       true,
                                                       this,
                                                       callfuncN_selector(LevelManager::pressedHardLevel));
//        menu->setOpacity(0.0f);
        menu->setPosition(ccp( visibleSize.width , visibleSize.height*0.47 ));
        this->addChild(menu , EnumLevelManagerTag_MenuHard , EnumLevelManagerTag_MenuHard);
        
        menu->startMoveInAction(0.4f);
    }
    
    {
        MenuActor *menu = MenuActor::createWithSetting(CCString::create("1 ~ 15 (Easy)"),
                                                       D_BlockGame_FontName,
                                                       76,
                                                       true,
                                                       this,
                                                       callfuncN_selector(LevelManager::pressedHardLevel));
//        menu->setOpacity(0.0f);
        menu->setPosition(ccp( visibleSize.width , visibleSize.height*0.26 ));
        this->addChild(menu , EnumLevelManagerTag_MenuHard , EnumLevelManagerTag_MenuHard);
        
        menu->startMoveInAction(0.8f);
    }
    
    
    
    
//    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
//    
//    // 產生第一個按鈕
//    {
//        CCLabelTTF *labelLow = CCLabelTTF::create("1 ~ 35 (Hard)", D_BlockGame_FontName , 76);
//        
//        CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(labelLow,
//                                                             this,
//                                                             menu_selector(LevelLayer::selectLevelHard));
//        menuLabel->setPosition( CCPointZero );
//        CCMenu *menu = CCMenu::create(menuLabel , NULL);
//        menu->setContentSize( CCSizeMake(menuLabel->getContentSize().width , menuLabel->getContentSize().height) );
//        menu->setPosition(ccp( visibleSize.width*0.9 , visibleSize.height*0.67 ));
//        
//        this->addChild(menu , EnumLevelSceneTag_MenuButton_Hard , EnumLevelSceneTag_MenuButton_Hard);
//        
//        CCMoveTo *moveToAction = CCMoveTo::create(0.5f, ccp(visibleSize.width*0.5, visibleSize.height*0.67 ));
//        CCEaseOut *easeAction = CCEaseOut::create(moveToAction, 1.0f);
//        CCFadeIn *fadeInAction = CCFadeIn::create(0.3f);
//        
//        CCSpawn *spawn = CCSpawn::create(easeAction , fadeInAction , NULL );
//        menu->runAction(spawn);
//        //        menu->runAction(easeAction);
//        //        menu->runAction(fadeInAction);
//        
//        
//    }
//    
//    // 產生第二個按鈕
//    {
//        CCLabelTTF *labelLow = CCLabelTTF::create("1 ~ 25  (Mid)", D_BlockGame_FontName , 76);
//        
//        CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(labelLow,
//                                                             this,
//                                                             menu_selector(LevelLayer::selectLevelNormal));
//        menuLabel->setPosition( CCPointZero );
//        CCMenu *menu = CCMenu::create(menuLabel , NULL);
//        menu->setOpacity(0.0f);
//        menu->setContentSize( CCSizeMake(menuLabel->getContentSize().width , menuLabel->getContentSize().height) );
//        menu->setPosition(ccp( visibleSize.width *0.9, visibleSize.height*0.47 ));
//        
//        this->addChild(menu , EnumLevelSceneTag_MenuButton_Normal , EnumLevelSceneTag_MenuButton_Normal);
//        
//        CCMoveTo *moveToAction = CCMoveTo::create(0.5f, ccp(visibleSize.width*0.5, visibleSize.height*0.47 ));
//        CCEaseOut *easeAction = CCEaseOut::create(moveToAction, 1.0f);
//        CCFadeIn *fadeInAction = CCFadeIn::create(0.3f);
//        
//        CCDelayTime *delay = CCDelayTime::create(0.4f);
//        
//        menu->runAction(CCSequence::create( delay , easeAction , NULL ));
//        menu->runAction(CCSequence::create( delay , fadeInAction , NULL ));
//    }
//    
//    
//    // 產生第三個按鈕
//    {
//        CCLabelTTF *labelLow = CCLabelTTF::create("1 ~ 15 (Easy)", D_BlockGame_FontName , 76);
//        
//        CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(labelLow,
//                                                             this,
//                                                             menu_selector(LevelLayer::selectLevelEasy));
//        menuLabel->setPosition( CCPointZero );
//        CCMenu *menu = CCMenu::create(menuLabel , NULL);
//        menu->setOpacity(0.0f);
//        menu->setContentSize( CCSizeMake(menuLabel->getContentSize().width , menuLabel->getContentSize().height) );
//        menu->setPosition(ccp( visibleSize.width*0.9 , visibleSize.height*0.26 ));
//        
//        this->addChild(menu , EnumLevelSceneTag_MenuButton_Easy , EnumLevelSceneTag_MenuButton_Easy);
//        
//        CCMoveTo *moveToAction = CCMoveTo::create(0.5f, ccp(visibleSize.width*0.5, visibleSize.height*0.26 ));
//        CCEaseOut *easeAction = CCEaseOut::create(moveToAction, 1.0f);
//        CCFadeIn *fadeInAction = CCFadeIn::create(0.3f);
//        
//        CCDelayTime *delay = CCDelayTime::create(0.8f);
//        
//        menu->runAction(CCSequence::create( delay , easeAction , NULL ));
//        menu->runAction(CCSequence::create( delay , fadeInAction , NULL ));
//    }
//
    
}

void LevelManager::startLevelAnimation(){
    
}

void LevelManager::endLevelAnimation(){
    
}

void LevelManager::pressedHardLevel(){
    
}

void LevelManager::pressedMidLevel(){
    
}

void LevelManager::pressedLowLevel(){
    
}



