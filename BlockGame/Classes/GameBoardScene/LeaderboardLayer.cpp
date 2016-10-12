//
//  LeaderboardLayer.cpp
//  BlockGame
//
//  Created by Chou Coody on 2016/10/11.
//
//

#include "LeaderboardLayer.h"

// for Tools
#include "PlayerDataTools.h"

// for Data
#include "LeaderboardData.h"

// for Constant
#include "BlockGameConstant.h"

USING_NS_CC;

bool LeaderboardLayer::init(){
    
    if ( CCLayerColor::initWithColor(D_BlockGame_BackgroundColor) ) {
        
        CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
        
        this->setOpacity(0.0f);
        this->setContentSize( visibleSize );
        this->setPosition(ccp(0, visibleSize.height*-1));
        
        return true;
    }
    
    return false;
}

void LeaderboardLayer::startLeaderboardAnimation(){
    
    CCCallFunc *layerAction = CCCallFunc::create(this, callfunc_selector(LeaderboardLayer::showLayerAnimation));
    
    CCDelayTime *delay = CCDelayTime::create(0.5f);
    
    CCCallFunc *backBtnAction = CCCallFunc::create(this, callfunc_selector(LeaderboardLayer::showBackBtnAnimation));
    
    CCCallFunc *initialData = CCCallFunc::create(this , callfunc_selector(LeaderboardLayer::initialLeaderboard));
    
    CCSequence *sequcnce = CCSequence::create( layerAction , delay , backBtnAction , delay , initialData , NULL );
    
    this->runAction(sequcnce);
    
}

void LeaderboardLayer::stopLeaderboardAnimation(){
    
    CCCallFunc *backBtnAction = CCCallFunc::create(this, callfunc_selector(LeaderboardLayer::hideBackBtnAnimation));
    
    CCDelayTime *delay = CCDelayTime::create(0.5f);
    
    CCCallFunc *layerAction = CCCallFunc::create(this, callfunc_selector(LeaderboardLayer::hideLayerAnimation));
    
    CCSequence *sequcnce = CCSequence::create( backBtnAction , delay , layerAction , CCCallFunc::create(this, callfunc_selector(LeaderboardLayer::removeAllChildren)) , NULL );
    
    this->runAction(sequcnce);
}

void LeaderboardLayer::initialLeaderboard(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCArray *dataArray = PlayerDataTools::sharedInstance()->getPlayerDataArray();
    
    if ( dataArray->count() > 0 ) {
        for ( int i = 0 ; i < dataArray->count() ; i++ ) {
            
            LeaderboardData *data = (LeaderboardData *)dataArray->objectAtIndex(i);
            
            CCLabelTTF *lv = CCLabelTTF::create(CCString::createWithFormat("%d" , i+1)->getCString() ,
                                                D_BlockGame_FontName,
                                                60);
            lv->setColor(ccc3(0, 0, 0));
            lv->setPosition(ccp(visibleSize.width*0.1, visibleSize.height*0.8 - 70*i));
            this->addChild(lv);
            
            CCLabelTTF *name = CCLabelTTF::create(data->getName()->getCString(),
                                                  D_BlockGame_FontName,
                                                  60);
            name->setColor(ccc3(0, 0, 0));
            name->setPosition(ccp(visibleSize.width*0.35, visibleSize.height*0.8 - 50*i));
            this->addChild(name);
            
            CCLabelTTF *score = CCLabelTTF::create( CCString::createWithFormat("%d" , data->getScore())->getCString() ,
                                                   D_BlockGame_FontName,
                                                   60);
            score->setColor(ccc3(0, 0, 0));
            score->setPosition(ccp(visibleSize.width*0.8, visibleSize.height*0.8 - 50*i));
            this->addChild(score);
            
        }
    }
    
    
}

void LeaderboardLayer::showBackBtnAnimation(){
    
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCLabelTTF *labelLow = CCLabelTTF::create("Back", D_BlockGame_FontName , 90);
    labelLow->setColor(ccc3(0, 0, 0));
    
    CCMenuItemLabel *menuLabel = CCMenuItemLabel::create(labelLow,
                                                         this,
                                                         menu_selector(LeaderboardLayer::back));
    menuLabel->setPosition( CCPointZero );
    CCMenu *menu = CCMenu::create(menuLabel , NULL);
    menu->setOpacity(0.0f);
    menu->setContentSize( CCSizeMake(menuLabel->getContentSize().width , menuLabel->getContentSize().height) );
    menu->setPosition(ccp( visibleSize.width*0.9 , visibleSize.height*0.93 ));
    
    this->addChild(menu , EnumLeaderboardLayerTag_BackBtn , EnumLeaderboardLayerTag_BackBtn);
    
    CCMoveTo *moveToAction = CCMoveTo::create(0.5f, ccp(visibleSize.width*0.2, visibleSize.height*0.93 ));
    CCEaseOut *easeAction = CCEaseOut::create(moveToAction, 1.0f);
    CCFadeIn *fadeInAction = CCFadeIn::create(0.3f);
    
    menu->runAction(easeAction);
    menu->runAction(fadeInAction);
}

;
void LeaderboardLayer::hideBackBtnAnimation(){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    {
        CCMenu *menu = (CCMenu *)this->getChildByTag(EnumLeaderboardLayerTag_BackBtn);
        
        CCMoveTo *moveToAction = CCMoveTo::create(0.35f, ccp( visibleSize.width*0.9 , visibleSize.height*0.26 ));
        CCEaseIn *easeAction = CCEaseIn::create(moveToAction, 1.0f);
        CCFadeOut *fadeOutAction = CCFadeOut::create(0.15f);
        
        CCDelayTime *delay = CCDelayTime::create(0.65f);
        
        menu->runAction(CCSequence::create(delay , easeAction , NULL));
        menu->runAction(CCSequence::create(delay , fadeOutAction , NULL));
    }
}

void LeaderboardLayer::showLayerAnimation(){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCMoveBy *moveBy = CCMoveBy::create(0.3f, ccp(0, visibleSize.height));
    CCFadeIn *fadeIn = CCFadeIn::create(0.3f);
    
    this->runAction(moveBy);
    this->runAction(fadeIn);
}

void LeaderboardLayer::hideLayerAnimation(){
    CCSize visibleSize = CCDirector::sharedDirector()->getVisibleSize();
    
    CCMoveBy *moveBy = CCMoveBy::create(0.3f, ccp(0, visibleSize.height*-1));
    CCFadeOut *fadeOut = CCFadeOut::create(0.3f);
    
    this->runAction(moveBy);
    this->runAction(fadeOut);
}

void LeaderboardLayer::back(){
    
    this->stopLeaderboardAnimation();
    
}
