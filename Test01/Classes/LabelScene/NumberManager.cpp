//
//  NumberManager.cpp
//  Test01
//
//  Created by CoodyChou on 2016/9/23.
//
//

#include "NumberManager.h"

USING_NS_CC;

typedef enum{
    
}EnumNumberManagerTag;

bool NumberManager::init(const char *pFontFileName){
    
    if ( CCNode::init() ) {
        
        m_pFontFileName = pFontFileName;
        
        return true;
    }
    return false;
}

void NumberManager::getJumpNumbers( unsigned int uNumbers ){
    this->getJumpNumbers(uNumbers, CCPointMake(0, 0));
}

void NumberManager::getJumpNumbers( unsigned int uNumbers , cocos2d::CCPoint moveByPoint){
    
    CCString *numberString = CCString::createWithFormat( "%d" , uNumbers );
    
    CCLabelBMFont *scoreNumber = CCLabelBMFont::create( "" , m_pFontFileName );
    scoreNumber->setScale(0.0f);
    scoreNumber->setString( numberString->getCString() );
    scoreNumber->setPosition( moveByPoint );
    this->addChild(scoreNumber);
    
    CCFadeIn *fadeInAction = CCFadeIn::create(0.15f);
    
    CCScaleTo *scaleBig = CCScaleTo::create(0.3f, 2.0f);
    CCEaseOut *easeOutAction = CCEaseOut::create(scaleBig, 0.3f);
    CCScaleTo *scaleSmall = CCScaleTo::create(0.3f, 1.0f);
    CCEaseIn *easeInAction = CCEaseIn::create(scaleSmall, 0.3f);
    
    CCDelayTime *delayAction = CCDelayTime::create(0.6f);
    
    CCFadeOut *fadeOutAction = CCFadeOut::create(0.4f);
    CCCallFuncN *funcAction = CCCallFuncN::create(this, callfuncN_selector(NumberManager::scaleJumpNumbers));
    
    CCSequence *sequenceAction = CCSequence::create(easeOutAction , easeInAction , delayAction , fadeOutAction , funcAction , NULL);
    
    scoreNumber->runAction(fadeInAction);
    scoreNumber->runAction(sequenceAction);

}

void NumberManager::scaleJumpNumbers(CCObject *pSender){
    CCLabelBMFont *scoreNumber = (CCLabelBMFont *)pSender;
    scoreNumber->setScale(0.0f);
    scoreNumber->removeFromParent();
}
