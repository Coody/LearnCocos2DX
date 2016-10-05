//
//  LevelScene.cpp
//  BlockGame
//
//  Created by Coody on 2016/9/30.
//
//

#include "LevelScene.h"

// for Scene
#include "GameBoardScene.h"

USING_NS_CC;

CCScene *LevelLayer::scene(){
    
    CCScene *scene = CCScene::create();
    
    LevelLayer *layer = LevelLayer::create();
    
    scene->addChild(layer);
    
    return scene;
}

bool LevelLayer::init(){
    
    if ( CCLayerColor::initWithColor(D_BlockGame_LevelLayerColor) ) {
        
        m_enumLevel = EnumGameBoard_Level_Easy;
        
        this->showLabelAnimation();
        
//        this->showMenuButtonAnimation();
        
        return true;
    }
    
    return false;
}

void LevelLayer::showLabelAnimation(){
    
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // Title
    CCLabelTTF *labelTTF = CCLabelTTF::create( "Select Level", D_BlockGame_FontName , 110);
    labelTTF->setPosition(ccp(visibleSize.width*0.5, visibleSize.height*0.9));
    labelTTF->setOpacity(0.0f);
    labelTTF->setScale(0.0f);
    this->addChild(labelTTF , EnumLevelSceneTag_TitleLabel , EnumLevelSceneTag_TitleLabel);
    
    CCDelayTime *delayTime = CCDelayTime::create(0.3f);

    CCScaleTo *scaleBig = CCScaleTo::create(0.6f, 1.0f);
    CCEaseOut *easeOutAction = CCEaseOut::create(scaleBig, 15.0f);
    
    CCFadeIn *fadeInAction = CCFadeIn::create(0.3f);
    
    CCCallFunc *showMenuAction = CCCallFunc::create(this , callfunc_selector(LevelLayer::showMenuButtonAnimation));
    
    labelTTF->runAction(CCSequence::create(delayTime , fadeInAction , NULL));
    labelTTF->runAction(CCSequence::create(delayTime , easeOutAction , showMenuAction , NULL));
    
}

void LevelLayer::hideLabelAnimation(){
    
    CCLabelTTF *labelTTF = (CCLabelTTF *)this->getChildByTag(EnumLevelSceneTag_TitleLabel);
    
    CCScaleTo *scaleSmall = CCScaleTo::create(0.3f, 0.0f);
    CCEaseIn *easeInAction = CCEaseIn::create(scaleSmall, 15.0f);
    
    CCFadeOut *fadeOutAction = CCFadeOut::create(0.15f);
    
    labelTTF->runAction(easeInAction);
    labelTTF->runAction(fadeOutAction);
    
}

void LevelLayer::showMenuButtonAnimation(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // 產生第一個按鈕
    {
        CCLabelTTF *labelLow = CCLabelTTF::create("1 ~ 35 (Hard)", D_BlockGame_FontName , 76);
        
        CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(labelLow,
                                                             this,
                                                             menu_selector(LevelLayer::selectLevelHard));
        menuLabel->setPosition( CCPointZero );
        CCMenu *menu = CCMenu::create(menuLabel , NULL);
        menu->setContentSize( CCSizeMake(menuLabel->getContentSize().width , menuLabel->getContentSize().height) );
        menu->setPosition(ccp( visibleSize.width*0.9 , visibleSize.height*0.67 ));
        
        this->addChild(menu , EnumLevelSceneTag_MenuButton_Hard , EnumLevelSceneTag_MenuButton_Hard);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.5f, ccp(visibleSize.width*0.5, visibleSize.height*0.67 ));
        CCEaseOut *easeAction = CCEaseOut::create(moveToAction, 1.0f);
        CCFadeIn *fadeInAction = CCFadeIn::create(0.3f);
        
        menu->runAction(easeAction);
        menu->runAction(fadeInAction);
        
    }
    
    // 產生第二個按鈕
    {
        CCLabelTTF *labelLow = CCLabelTTF::create("1 ~ 25  (Mid)", D_BlockGame_FontName , 76);
        
        CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(labelLow,
                                                             this,
                                                             menu_selector(LevelLayer::selectLevelNormal));
        menuLabel->setPosition( CCPointZero );
        CCMenu *menu = CCMenu::create(menuLabel , NULL);
        menu->setOpacity(0.0f);
        menu->setContentSize( CCSizeMake(menuLabel->getContentSize().width , menuLabel->getContentSize().height) );
        menu->setPosition(ccp( visibleSize.width *0.9, visibleSize.height*0.47 ));
        
        this->addChild(menu , EnumLevelSceneTag_MenuButton_Normal , EnumLevelSceneTag_MenuButton_Normal);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.5f, ccp(visibleSize.width*0.5, visibleSize.height*0.47 ));
        CCEaseOut *easeAction = CCEaseOut::create(moveToAction, 1.0f);
        CCFadeIn *fadeInAction = CCFadeIn::create(0.3f);
        
        CCDelayTime *delay = CCDelayTime::create(0.4f);
        
        menu->runAction(CCSequence::create( delay , easeAction , NULL ));
        menu->runAction(CCSequence::create( delay , fadeInAction , NULL ));
    }

    
    // 產生第三個按鈕
    {
        CCLabelTTF *labelLow = CCLabelTTF::create("1 ~ 15 (Easy)", D_BlockGame_FontName , 76);
        
        CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(labelLow,
                                                             this,
                                                             menu_selector(LevelLayer::selectLevelEasy));
        menuLabel->setPosition( CCPointZero );
        CCMenu *menu = CCMenu::create(menuLabel , NULL);
        menu->setOpacity(0.0f);
        menu->setContentSize( CCSizeMake(menuLabel->getContentSize().width , menuLabel->getContentSize().height) );
        menu->setPosition(ccp( visibleSize.width*0.9 , visibleSize.height*0.26 ));
        
        this->addChild(menu , EnumLevelSceneTag_MenuButton_Easy , EnumLevelSceneTag_MenuButton_Easy);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.5f, ccp(visibleSize.width*0.5, visibleSize.height*0.26 ));
        CCEaseOut *easeAction = CCEaseOut::create(moveToAction, 1.0f);
        CCFadeIn *fadeInAction = CCFadeIn::create(0.3f);
        
        CCDelayTime *delay = CCDelayTime::create(0.8f);
        
        menu->runAction(CCSequence::create( delay , easeAction , NULL ));
        menu->runAction(CCSequence::create( delay , fadeInAction , NULL ));
    }
    
}

void LevelLayer::hideMenuButtonAnimation(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    {
        CCMenu *menu = (CCMenu *)this->getChildByTag(EnumLevelSceneTag_MenuButton_Easy);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.35f, ccp( visibleSize.width*0.9 , visibleSize.height*0.26 ));
        CCEaseIn *easeAction = CCEaseIn::create(moveToAction, 1.0f);
        CCFadeOut *fadeOutAction = CCFadeOut::create(0.15f);
        
        CCDelayTime *delay = CCDelayTime::create(0.65f);
        
        menu->runAction(CCSequence::create(delay , easeAction , NULL));
        menu->runAction(CCSequence::create(delay , fadeOutAction , NULL));
    }
    
    {
        CCMenu *menu = (CCMenu *)this->getChildByTag(EnumLevelSceneTag_MenuButton_Normal);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.35f, ccp( visibleSize.width*0.9 , visibleSize.height*0.47 ));
        CCEaseIn *easeAction = CCEaseIn::create(moveToAction, 1.0f);
        CCFadeOut *fadeOutAction = CCFadeOut::create(0.15f);
        
        CCDelayTime *delay = CCDelayTime::create(0.25f);
        
        menu->runAction(CCSequence::create(delay , easeAction , NULL));
        menu->runAction(CCSequence::create(delay , fadeOutAction , NULL));
    }
    
    {
        CCMenu *menu = (CCMenu *)this->getChildByTag(EnumLevelSceneTag_MenuButton_Hard);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.35f, ccp( visibleSize.width*0.9 , visibleSize.height*0.67 ));
        CCEaseIn *easeAction = CCEaseIn::create(moveToAction, 1.0f);
        CCFadeOut *fadeOutAction = CCFadeOut::create(0.15f);
        
        menu->runAction(easeAction);
        menu->runAction(fadeOutAction);
    }
}

void LevelLayer::selectLevelEasy(){
    
    this->setMenuTouchDisable();
    
    m_enumLevel = EnumGameBoard_Level_Easy;
    
    // all Action
    this->hideLabelAnimation();
    this->hideMenuButtonAnimation();
    
    CCDelayTime *delayChangeScene = CCDelayTime::create(1.0f);
    CCCallFunc *changeSceneAction = CCCallFunc::create(this, callfunc_selector(LevelLayer::changeScene));
    this->runAction(CCSequence::create(delayChangeScene , changeSceneAction , NULL));
}

void LevelLayer::selectLevelNormal(){
    
    this->setMenuTouchDisable();
    
    m_enumLevel = EnumGameBoard_Level_Normal;
    
    // all Action
    this->hideLabelAnimation();
    this->hideMenuButtonAnimation();
    
    CCDelayTime *delayChangeScene = CCDelayTime::create(1.0f);
    CCCallFunc *changeSceneAction = CCCallFunc::create(this, callfunc_selector(LevelLayer::changeScene));
    this->runAction(CCSequence::create(delayChangeScene , changeSceneAction , NULL));
}

void LevelLayer::selectLevelHard(){
    
    this->setMenuTouchDisable();
    
    m_enumLevel = EnumGameBoard_Level_Hard;
    
    // all Action
    this->hideLabelAnimation();
    this->hideMenuButtonAnimation();
    
    CCDelayTime *delayChangeScene = CCDelayTime::create(1.0f);
    CCCallFunc *changeSceneAction = CCCallFunc::create(this, callfunc_selector(LevelLayer::changeScene));
    this->runAction(CCSequence::create(delayChangeScene , changeSceneAction , NULL));
}

void LevelLayer::changeScene(){
    CCScene *pScene = GameBoardLayer::scene( m_enumLevel );
    CCDirector::sharedDirector()->replaceScene(pScene);
}

void LevelLayer::setMenuTouchDisable(){
    CCMenu *menu1 = (CCMenu *)this->getChildByTag(EnumLevelSceneTag_MenuButton_Easy);
    menu1->setTouchEnabled( false );
    CCMenu *menu2 = (CCMenu *)this->getChildByTag(EnumLevelSceneTag_MenuButton_Normal);
    menu2->setTouchEnabled( false );
    CCMenu *menu3 = (CCMenu *)this->getChildByTag(EnumLevelSceneTag_MenuButton_Hard);
    menu3->setTouchEnabled( false );
}

