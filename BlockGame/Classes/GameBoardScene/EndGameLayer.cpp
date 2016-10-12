//
//  EndGameLayer.cpp
//  BlockGame
//
//  Created by Chou Coody on 2016/10/10.
//
//

#include "EndGameLayer.h"

// for Constant
#include "BlockGameConstant.h"

// for Scene
#include "StartMenuScene.h"

// for Layer
#include "LeaderboardLayer.h"

USING_NS_CC;

bool EndGameLayer::init(){
    
    if ( CCLayerColor::initWithColor( D_BlockGame_GreenColor ) ) {
        
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        
        this->setContentSize(visibleSize);
        this->setOpacity(0.0f);
        this->setPosition(ccp(0, -100));
        
        return true;
        
    }
    
    return false;
}

void EndGameLayer::startInitialLayer(){
    
    CCCallFunc *showLayerAnimation = CCCallFunc::create(this , callfunc_selector(EndGameLayer::showLayerAnimation));
    
    CCCallFunc *showTitleAnimation = CCCallFunc::create(this, callfunc_selector(EndGameLayer::showTitleAnimation));
    
    CCDelayTime *delay = CCDelayTime::create(0.5f);
    
    CCSequence *sequenceAction = CCSequence::create( showLayerAnimation , delay , showTitleAnimation , NULL );
    
    this->runAction(sequenceAction);
    
}

void EndGameLayer::setTryAgainBlock(cocos2d::CCObject *targetObj ,
                      cocos2d::SEL_CallFuncN selDisappearDone )
{
    
}

void EndGameLayer::stopInitialLayer(){
    
    CCCallFunc *hideTitleAnimation = CCCallFunc::create(this, callfunc_selector(EndGameLayer::hideTitleAnimation));
    
    CCDelayTime *delay1 = CCDelayTime::create(0.4f);
    CCDelayTime *delay2 = CCDelayTime::create(1.2f);
    
    CCCallFunc *hideMenuAnimation = CCCallFunc::create(this , callfunc_selector(EndGameLayer::hideMenuButtonAnimation));
    
    CCCallFunc *hideLayerAnimation = CCCallFunc::create(this , callfunc_selector(EndGameLayer::hideLayerAnimation));
    
    CCSequence *sequenceAction = CCSequence::create( hideTitleAnimation , delay1 , hideMenuAnimation , delay2 , hideLayerAnimation , NULL );
    
    this->runAction(sequenceAction);
}

#pragma mark - Private
void EndGameLayer::showLayerAnimation(){
    CCMoveBy *moveBy = CCMoveBy::create(0.3f, ccp(0, 100));
    CCFadeIn *fadeIn = CCFadeIn::create(0.2f);
    this->runAction(moveBy);
    this->runAction(fadeIn);
}

void EndGameLayer::hideLayerAnimation(){
    CCMoveBy *moveBy = CCMoveBy::create(0.5f, ccp(0, -100));
    CCFadeOut *fadeOut = CCFadeOut::create(0.2f);
    this->runAction(moveBy);
    this->runAction(fadeOut);
}

void EndGameLayer::showTitleAnimation(){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // Title
    CCLabelTTF *labelTTF = CCLabelTTF::create( "Game Over!", D_BlockGame_FontName , 110);
    labelTTF->setPosition(ccp(visibleSize.width*0.5, visibleSize.height*0.9));
    labelTTF->setOpacity(0.0f);
    labelTTF->setScale(0.0f);
    this->addChild(labelTTF , EnumEndGameLayerTag_Title , EnumEndGameLayerTag_Title);
    
    CCDelayTime *delayTime = CCDelayTime::create(0.3f);
    
    CCScaleTo *scaleBig = CCScaleTo::create(0.6f, 1.0f);
    CCEaseOut *easeOutAction = CCEaseOut::create(scaleBig, 15.0f);
    
    CCFadeIn *fadeInAction = CCFadeIn::create(0.3f);
    
    CCCallFunc *showMenuAction = CCCallFunc::create(this , callfunc_selector(EndGameLayer::showMenuButtonAnimation));
    
    labelTTF->runAction(CCSequence::create(delayTime , fadeInAction , NULL));
    labelTTF->runAction(CCSequence::create(delayTime , easeOutAction , showMenuAction , NULL));
}

void EndGameLayer::hideTitleAnimation(){
    CCLabelTTF *labelTTF = (CCLabelTTF *)this->getChildByTag(EnumEndGameLayerTag_Title);
    
    CCScaleTo *scaleSmall = CCScaleTo::create(0.3f, 0.0f);
    CCEaseIn *easeInAction = CCEaseIn::create(scaleSmall, 15.0f);
    
    CCFadeOut *fadeOutAction = CCFadeOut::create(0.15f);
    
    labelTTF->runAction(easeInAction);
    labelTTF->runAction(fadeOutAction);
}

void EndGameLayer::initialMenu(){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    // 產生第一個按鈕
    {
        CCLabelTTF *labelLow = CCLabelTTF::create("Try Again", D_BlockGame_FontName , 76);
        
        CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(labelLow,
                                                             this,
                                                             menu_selector(EndGameLayer::pressedTryAgain));
        menuLabel->setPosition( CCPointZero );
        CCMenu *menu = CCMenu::create(menuLabel , NULL);
        menu->setOpacity(0.0f);
        menu->setContentSize( CCSizeMake(menuLabel->getContentSize().width , menuLabel->getContentSize().height) );
        menu->setPosition(ccp( visibleSize.width*0.9 , visibleSize.height*0.67 ));
        
        this->addChild(menu , EnumEndGameLayerTag_TryAgain , EnumEndGameLayerTag_TryAgain);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.5f, ccp(visibleSize.width*0.5, visibleSize.height*0.67 ));
        CCEaseOut *easeAction = CCEaseOut::create(moveToAction, 1.0f);
        CCFadeIn *fadeInAction = CCFadeIn::create(0.3f);
        
        menu->runAction(easeAction);
        menu->runAction(fadeInAction);
        
    }
    
    // 產生第二個按鈕
    {
        CCLabelTTF *labelLow = CCLabelTTF::create("Leaderboard", D_BlockGame_FontName , 76);
        
        CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(labelLow,
                                                             this,
                                                             menu_selector(EndGameLayer::pressedLeaderboard));
        menuLabel->setPosition( CCPointZero );
        CCMenu *menu = CCMenu::create(menuLabel , NULL);
        menu->setOpacity(0.0f);
        menu->setContentSize( CCSizeMake(menuLabel->getContentSize().width , menuLabel->getContentSize().height) );
        menu->setPosition(ccp( visibleSize.width *0.9, visibleSize.height*0.47 ));
        
        this->addChild(menu , EnumEndGameLayerTag_Leaderboard , EnumEndGameLayerTag_Leaderboard);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.5f, ccp(visibleSize.width*0.5, visibleSize.height*0.47 ));
        CCEaseOut *easeAction = CCEaseOut::create(moveToAction, 1.0f);
        CCFadeIn *fadeInAction = CCFadeIn::create(0.3f);
        
        CCDelayTime *delay = CCDelayTime::create(0.4f);
        
        menu->runAction(CCSequence::create( delay , easeAction , NULL ));
        menu->runAction(CCSequence::create( delay , fadeInAction , NULL ));
    }
    
    
    // 產生第三個按鈕
    {
        CCLabelTTF *labelLow = CCLabelTTF::create("Restart", D_BlockGame_FontName , 76);
        
        CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(labelLow,
                                                             this,
                                                             menu_selector(EndGameLayer::pressedRestart));
        menuLabel->setPosition( CCPointZero );
        CCMenu *menu = CCMenu::create(menuLabel , NULL);
        menu->setOpacity(0.0f);
        menu->setContentSize( CCSizeMake(menuLabel->getContentSize().width , menuLabel->getContentSize().height) );
        menu->setPosition(ccp( visibleSize.width*0.9 , visibleSize.height*0.26 ));
        
        this->addChild(menu , EnumEndGameLayerTag_Restart , EnumEndGameLayerTag_Restart);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.5f, ccp(visibleSize.width*0.5, visibleSize.height*0.26 ));
        CCEaseOut *easeAction = CCEaseOut::create(moveToAction, 1.0f);
        CCFadeIn *fadeInAction = CCFadeIn::create(0.3f);
        
        CCDelayTime *delay = CCDelayTime::create(0.8f);
        
        menu->runAction(CCSequence::create( delay , easeAction , NULL ));
        menu->runAction(CCSequence::create( delay , fadeInAction , NULL ));
    }
}

void EndGameLayer::hideMenuButtonAnimation(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    {
        CCMenu *menu = (CCMenu *)this->getChildByTag(EnumEndGameLayerTag_Restart);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.35f, ccp( visibleSize.width*0.9 , visibleSize.height*0.26 ));
        CCEaseIn *easeAction = CCEaseIn::create(moveToAction, 1.0f);
        CCFadeOut *fadeOutAction = CCFadeOut::create(0.15f);
        
        CCDelayTime *delay = CCDelayTime::create(0.65f);
        
        menu->runAction(CCSequence::create(delay , easeAction , NULL));
        menu->runAction(CCSequence::create(delay , fadeOutAction , NULL));
    }
    
    {
        CCMenu *menu = (CCMenu *)this->getChildByTag(EnumEndGameLayerTag_Leaderboard);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.35f, ccp( visibleSize.width*0.9 , visibleSize.height*0.47 ));
        CCEaseIn *easeAction = CCEaseIn::create(moveToAction, 1.0f);
        CCFadeOut *fadeOutAction = CCFadeOut::create(0.15f);
        
        CCDelayTime *delay = CCDelayTime::create(0.25f);
        
        menu->runAction(CCSequence::create(delay , easeAction , NULL));
        menu->runAction(CCSequence::create(delay , fadeOutAction , NULL));
    }
    
    {
        CCMenu *menu = (CCMenu *)this->getChildByTag(EnumEndGameLayerTag_TryAgain);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.35f, ccp( visibleSize.width*0.9 , visibleSize.height*0.67 ));
        CCEaseIn *easeAction = CCEaseIn::create(moveToAction, 1.0f);
        CCFadeOut *fadeOutAction = CCFadeOut::create(0.15f);
        
        menu->runAction(easeAction);
        menu->runAction(fadeOutAction);
    }
}

void EndGameLayer::pressedTryAgain(){
    
}

void EndGameLayer::pressedLeaderboard(){
    LeaderboardLayer *leaderboardLayer = (LeaderboardLayer *)this->getChildByTag(EnumEndGameLayerTag_LeaderboardLayer);
    if ( leaderboardLayer == NULL ) {
        leaderboardLayer = LeaderboardLayer::create();
        this->addChild(leaderboardLayer , EnumEndGameLayerTag_LeaderboardLayer , EnumEndGameLayerTag_LeaderboardLayer);
    }
    leaderboardLayer->startLeaderboardAnimation();
}

void EndGameLayer::pressedRestart(){
    
    CCCallFunc *hideTitleAnimation = CCCallFunc::create(this, callfunc_selector(EndGameLayer::hideTitleAnimation));
    
    CCDelayTime *delay1 = CCDelayTime::create(0.4f);
    CCDelayTime *delay2 = CCDelayTime::create(1.2f);
    
    CCCallFunc *hideMenuAnimation = CCCallFunc::create(this , callfunc_selector(EndGameLayer::hideMenuButtonAnimation));
    
    CCCallFunc *changeScene = CCCallFunc::create(this , callfunc_selector(EndGameLayer::changeSceneToStartMScene));
    
    CCSequence *sequenceAction = CCSequence::create( hideTitleAnimation , delay1 , hideMenuAnimation , delay2 , changeScene , NULL );
    
    this->runAction(sequenceAction);
}

void EndGameLayer::changeSceneToStartMScene(){
    CCScene *scene = StartMenuLayer::scene();
    CCTransitionFade *fade = CCTransitionFade::create(0.3f, scene, ccc3(56, 174, 82));
    CCDirector::sharedDirector()->replaceScene(fade);
}

void EndGameLayer::showMenuButtonAnimation(){
    this->initialMenu();
}

