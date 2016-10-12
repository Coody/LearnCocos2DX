//
//  StartMenuScene.cpp
//  BlockGame
//
//  Created by Coody on 2016/9/30.
//
//

#include "StartMenuScene.h"

// for Constant
#include "BlockGameConstant.h"

// for Scene
#include "LevelScene.h"

// for Sound
#include "SimpleAudioEngine.h"

// for Tools
//#include "ActionTools.h"

USING_NS_CC;
using namespace CocosDenshion;

typedef enum{
    EnumStartMenuSceneZPosition_Man = 10,
    EnumStartMenuSceneZPosition_GameBoard = 20,
    EnumStartMenuSceneZPosition_Finger = 100,
    EnumStartMenuSceneZPosition_MenuButton = 110
}EnumStartMenuSceneZPosition;

#pragma mark - Public
bool StartMenuLayer::init(){
    
    if ( CCLayerColor::initWithColor(D_BlockGame_BackgroundColor) ) {
        
        m_uiSoundPlayCount = 0;
        isStartBgMusic = false;
        
        this->createGameBoardAnimation();
        
        this->createManAnimation();
        
        this->createMenuButton();
        
        this->createGameTitle();
        
        return true;
    }
    
    return false;
}

CCScene *StartMenuLayer::scene(){
    
    CCScene *scene = CCScene::create();
    
    StartMenuLayer *startMenuLayer = StartMenuLayer::create();
    
    scene->addChild(startMenuLayer);
    
    return scene;
    
}

#pragma mark - Private
void StartMenuLayer::createGameTitle(){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCLabelTTF *labelTTF = CCLabelTTF::create( "Hit!Hit!Hit!", "From Cartoon Blocks" , 100);
    labelTTF->setColor(ccBLACK);
    labelTTF->setPosition(ccp(visibleSize.width*0.5, visibleSize.height*0.7));
    this->addChild(labelTTF);
    
    CCScaleTo *scaleALittleBig = CCScaleTo::create(0.044, 1.2f);
    CCEaseIn *easeInAction = CCEaseIn::create(scaleALittleBig, 0.5f);
    CCScaleTo *scaleALittleSmall = CCScaleTo::create(0.044, 1.0f);
    CCEaseOut *easeOutAction = CCEaseOut::create(scaleALittleSmall, 0.5f);
    CCDelayTime *delayALittleTime = CCDelayTime::create(0.46f);
    
    CCCallFunc *func = CCCallFunc::create(this, callfunc_selector(StartMenuLayer::playHeartBeatSound));
    
    CCSequence *sequenceHeartBit = CCSequence::create(easeInAction , func , easeOutAction , delayALittleTime , NULL);
    CCRepeatForever *repeatForever = CCRepeatForever::create(sequenceHeartBit);
    
    labelTTF->runAction(repeatForever);
    
    this->preloadSounds();
}

void StartMenuLayer::createManAnimation(){
    
    
    
}

void StartMenuLayer::createGameBoardAnimation(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCSprite *bgSprite = CCSprite::create( "startMenuBG.png" );
    bgSprite->setPosition( ccp( visibleSize.width*0.5 , -100));
    
    this->addChild(bgSprite , EnumStartMenuSceneTag_GameBoard , EnumStartMenuSceneTag_GameBoard);
    
}

void StartMenuLayer::createMenuButton(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCMenuItemImage *menuItemImage = CCMenuItemImage::create("blockButton.png" ,
                                                             "blockButtonSelected.png",
                                                             this,
                                                             menu_selector(StartMenuLayer::selectedMenuButton));
    menuItemImage->setPosition( ccp(0, 0) );
    
    CCMenu *menu = CCMenu::create( menuItemImage , NULL );
    menu->setContentSize( CCSizeMake(menuItemImage->getContentSize().width, menuItemImage->getContentSize().height));
    menu->setPosition( ccp( visibleSize.width*0.33 , visibleSize.height*0.3) );
    this->addChild( menu , EnumStartMenuSceneTag_MenuButton , EnumStartMenuSceneTag_MenuButton );
}

void StartMenuLayer::selectedMenuButton(){
    
    CCSprite *bgSprite = (CCSprite *)this->getChildByTag(EnumStartMenuSceneTag_GameBoard);
    
    CCMoveBy *moveDown = CCMoveBy::create(0.3f, ccp(0, -40));
    CCEaseOut *easeOut = CCEaseOut::create(moveDown, 0.7f);
    CCMoveBy *moveUp = CCMoveBy::create(0.15, ccp(0, 400));
    CCEaseIn *easeIn = CCEaseIn::create(moveUp, 0.7f);
    
    CCDelayTime *delay = CCDelayTime::create(0.15f);
    
    CCSequence *bgSequenceAction = CCSequence::create(easeOut , delay , easeIn , NULL);
    bgSprite->runAction(bgSequenceAction);
    
    
    // menu 按鈕動畫消失
    CCMenu *menu = (CCMenu *)this->getChildByTag(EnumStartMenuSceneTag_MenuButton);
    menu->setEnabled(false);
    
    CCScaleBy *scaleBigAction = CCScaleBy::create(0.3f, 1.5f);
    CCEaseIn *easeBigAction = CCEaseIn::create(scaleBigAction, 0.7f);
    
    CCScaleBy *scaleSmallAction = CCScaleBy::create(0.15f, 0.0f);
    CCEaseOut *easeSmallAction = CCEaseOut::create(scaleSmallAction, 0.7f);
    
    CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(StartMenuLayer::changeScene));
    
    CCSequence *sequenceAction = CCSequence::create( easeBigAction , delay , easeSmallAction , funcAction , NULL);
    
    menu->runAction(sequenceAction);
    
}

void StartMenuLayer::changeScene(){
    
    CCScene *pScene = LevelLayer::scene();
    
    CCDirector::sharedDirector()->replaceScene(pScene);
    
}

void StartMenuLayer::playHeartBeatSound(){
    
    
    if ( m_uiSoundPlayCount > 40 ) {
        m_uiSoundPlayCount = 40;
    }
    switch ( m_uiSoundPlayCount / 4) {
        case 5:
        case 4:
        case 3:
        {
            
        }
        case 2:
        {
//            CCDelayTime *delay = CCDelayTime::create(0.02);
//            CCDelayTime *delay2 = CCDelayTime::create(0.04);
//            CCCallFunc *playSound = CCCallFunc::create(this , callfunc_selector(StartMenuLayer::playHeartBeatSound3));
//            CCSequence *sequence = CCSequence::create( delay , playSound , delay2 , playSound, NULL );
//            this->runAction(sequence);
            
            // play once
            if ( isStartBgMusic == false ) {
                isStartBgMusic = true;
                SimpleAudioEngine::sharedEngine()->playBackgroundMusic( "startMenuMusic.mp3", true);
            }

        }
        case 1:
        {
            CCDelayTime *delay = CCDelayTime::create(0.02);
            CCCallFunc *playSound = CCCallFunc::create(this , callfunc_selector(StartMenuLayer::playHeartBeatSound2));
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

void StartMenuLayer::preloadSounds(){
    
    // StartMenu
    SimpleAudioEngine::sharedEngine()->preloadEffect( "tap.mp3" );
    SimpleAudioEngine::sharedEngine()->preloadEffect( "tap2.mp3" );
    SimpleAudioEngine::sharedEngine()->preloadEffect( "tap4.mp3" );
    SimpleAudioEngine::sharedEngine()->preloadBackgroundMusic( "startMenuMusic.mp3" );
    SimpleAudioEngine::sharedEngine()->
    
    // GameBoard
    SimpleAudioEngine::sharedEngine()->preloadEffect( "blockDown.mp3" );
    SimpleAudioEngine::sharedEngine()->preloadEffect( "blockDisappear.mp3" );
    SimpleAudioEngine::sharedEngine()->preloadEffect( "blockTouchFail.mp3" );
}

void StartMenuLayer::playHeartBeatSound2(){
    SimpleAudioEngine::sharedEngine()->playEffect( "tap2.mp3" );
}

void StartMenuLayer::playHeartBeatSound3(){
    SimpleAudioEngine::sharedEngine()->playEffect( "tap4.mp3" );
}

void StartMenuLayer::playBGMusic(){
    SimpleAudioEngine::sharedEngine()->playBackgroundMusic( "startMenuMusic.mp3", true );
}


