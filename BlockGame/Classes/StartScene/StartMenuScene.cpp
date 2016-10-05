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

// for Tools
//#include "ActionTools.h"

USING_NS_CC;

typedef enum{
    EnumStartMenuSceneZPosition_Man = 10,
    EnumStartMenuSceneZPosition_GameBoard = 20,
    EnumStartMenuSceneZPosition_Finger = 100,
    EnumStartMenuSceneZPosition_MenuButton = 110
}EnumStartMenuSceneZPosition;

#pragma mark - Public
bool StartMenuLayer::init(){
    
    if ( CCLayerColor::initWithColor(D_BlockGame_BackgroundColor) ) {
        
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
    
    CCScaleTo *scaleALittleBig = CCScaleTo::create(0.05, 1.2f);
    CCEaseIn *easeInAction = CCEaseIn::create(scaleALittleBig, 0.5f);
    CCScaleTo *scaleALittleSmall = CCScaleTo::create(0.05, 1.0f);
    CCEaseOut *easeOutAction = CCEaseOut::create(scaleALittleSmall, 0.5f);
    CCDelayTime *delayALittleTime = CCDelayTime::create(0.45f);
    CCSequence *sequenceHeartBit = CCSequence::create(easeInAction , easeOutAction , delayALittleTime , NULL);
    CCRepeatForever *repeatForever = CCRepeatForever::create(sequenceHeartBit);
    
    labelTTF->runAction(repeatForever);
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







