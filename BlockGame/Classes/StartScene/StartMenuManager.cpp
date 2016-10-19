//
//  StartMenuManager.cpp
//  BlockGame
//
//  Created by Coody on 2016/10/17.
//
//

#include "StartMenuManager.h"

// for Constant
#include "BlockGameConstant.h"

// for Scene
#include "LevelScene.h"

// for Actor
#include "TitleLabelActor.h"

// for Sound
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace CocosDenshion;

StartMenuManager::StartMenuManager(){
    
}

StartMenuManager::~StartMenuManager(){
    
}

bool StartMenuManager::init(){
    if ( CCLayerColor::initWithColor(D_BlockGame_BackgroundColor) ) {
        
        // 建立 title
        this->initialTitle();
        
        this->initialBackground();
        
        this->initialMenuButton();
        
//        this->preloadSounds();
//        
//        this->playBGMusic();
        
        return true;
    }
    return false;
}

void StartMenuManager::startTitleHeartBeat(){
    TitleLabelActor *titleLabel = (TitleLabelActor *)this->getChildByTag(EnumStartMenuManagerTag_Title);
    titleLabel->startHeartBitAction();
}

#pragma mark - Private
void StartMenuManager::initialTitle(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    TitleLabelActor *startMenuTitleActor = TitleLabelActor::createWithSetting(CCString::create("Hit!Hit!Hit!") ,
                                                                              D_BlockGame_FontName,
                                                                              100,
                                                                              false,
                                                                              false);
    startMenuTitleActor->setScale(0.0f);
    this->addChild(startMenuTitleActor , EnumStartMenuManagerTag_Title , EnumStartMenuManagerTag_Title);
    startMenuTitleActor->setPosition(ccp(visibleSize.width*0.5, visibleSize.height*0.7));
}

void StartMenuManager::initialBackground(){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSprite *bgSprite = CCSprite::create( "startMenuBG.png" );
    bgSprite->setPosition( ccp( visibleSize.width*0.5 , -100));
    
    this->addChild(bgSprite , EnumStartMenuManagerTag_GameBoard , EnumStartMenuManagerTag_GameBoard);
}

void StartMenuManager::initialMenuButton(){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCMenuItemImage *menuItemImage = CCMenuItemImage::create("blockButton.png" ,
                                                             "blockButtonSelected.png",
                                                             this,
                                                             menu_selector(StartMenuManager::selectedMenuButton));
    menuItemImage->setPosition( ccp(0, 0) );
    
    CCMenu *menu = CCMenu::create( menuItemImage , NULL );
    menu->setContentSize( CCSizeMake(menuItemImage->getContentSize().width, menuItemImage->getContentSize().height));
    menu->setPosition( ccp( visibleSize.width*0.33 , visibleSize.height*0.3) );
    this->addChild( menu , EnumStartMenuManagerTag_MenuButton , EnumStartMenuManagerTag_MenuButton );
}

void StartMenuManager::changeScene(){
    
    CCScene *pScene = LevelLayer::scene();
    
    CCDirector::sharedDirector()->replaceScene(pScene);
    
}

void StartMenuManager::selectedMenuButton(){
    
    this->playButtonPressed();
    
    CCSprite *bgSprite = (CCSprite *)this->getChildByTag(EnumStartMenuManagerTag_GameBoard);
    
    CCMoveBy *moveDown = CCMoveBy::create(0.3f, ccp(0, -40));
    CCEaseOut *easeOut = CCEaseOut::create(moveDown, 0.7f);
    CCMoveBy *moveUp = CCMoveBy::create(0.15, ccp(0, 400));
    CCEaseIn *easeIn = CCEaseIn::create(moveUp, 0.7f);
    
    CCDelayTime *delay = CCDelayTime::create(0.15f);
    
    CCSequence *bgSequenceAction = CCSequence::create(easeOut , delay , easeIn , NULL);
    bgSprite->runAction(bgSequenceAction);
    
    
    // menu 按鈕動畫消失
    CCMenu *menu = (CCMenu *)this->getChildByTag(EnumStartMenuManagerTag_MenuButton);
    menu->setEnabled(false);
    
    CCScaleBy *scaleBigAction = CCScaleBy::create(0.3f, 1.5f);
    CCEaseIn *easeBigAction = CCEaseIn::create(scaleBigAction, 0.7f);
    
    CCScaleBy *scaleSmallAction = CCScaleBy::create(0.15f, 0.0f);
    CCEaseOut *easeSmallAction = CCEaseOut::create(scaleSmallAction, 0.7f);
    
    CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(StartMenuManager::changeScene));
    
    CCSequence *sequenceAction = CCSequence::create( easeBigAction , delay , easeSmallAction , funcAction , NULL);
    
    menu->runAction(sequenceAction);
    
}

#pragma mark - Private
void StartMenuManager::playHeartBeatSound(){
    
    
    if ( m_uiSoundPlayCount > 40 ) {
        m_uiSoundPlayCount = 40;
    }
    switch ( m_uiSoundPlayCount / 4) {
        case 5:
        case 4:
        case 3:
        case 2:
        {
            // play once
            if ( isStartBgMusic == false ) 
            {
                isStartBgMusic = true;
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic( "startMenuBGMusic.mp3", true);
            }
            
        }
        case 1:
        {
            CCDelayTime *delay = CCDelayTime::create(0.02);
            CCCallFunc *playSound = CCCallFunc::create(this , callfunc_selector(StartMenuManager::playHeartBeatSound2));
            CCSequence *sequence = CCSequence::create( delay , playSound , NULL );
            this->runAction(sequence);
        }
        case 0:
        default:
            SimpleAudioEngine::sharedEngine()->playEffect( "tap.mp3" );
            break;
    }
    m_uiSoundPlayCount = m_uiSoundPlayCount + 1;
}

void StartMenuManager::preloadSounds(){
    
    // StartMenu
    SimpleAudioEngine::sharedEngine()->preloadEffect( "tap.mp3" );
    SimpleAudioEngine::sharedEngine()->preloadEffect( "tap2.mp3" );
    SimpleAudioEngine::sharedEngine()->preloadEffect( "tap4.mp3" );
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic( "startMenuBGMusic.mp3" );
    SimpleAudioEngine::sharedEngine()->
    
    // GameBoard
    SimpleAudioEngine::sharedEngine()->preloadEffect( "blockDown.mp3" );
    SimpleAudioEngine::sharedEngine()->preloadEffect( "blockDisappear.mp3" );
    SimpleAudioEngine::sharedEngine()->preloadEffect( "blockTouchFail.mp3" );
}

void StartMenuManager::playHeartBeatSound2(){
    SimpleAudioEngine::sharedEngine()->playEffect( "tap2.mp3" );
}

void StartMenuManager::playHeartBeatSound3(){
    SimpleAudioEngine::sharedEngine()->playEffect( "tap4.mp3" );
}

void StartMenuManager::playBGMusic(){
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic( "startMenuBGMusic.mp3", true );
}

void StartMenuManager::playButtonPressed(){
//    SimpleAudioEngine::sharedEngine()->playEffect( "startMenuBtnPressed.mp3" );
}

