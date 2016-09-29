//
//  PokerActor.cpp
//  Test01
//
//  Created by Coody on 2016/9/20.
//
//

#include "PokerActor.h"

// for define
#include "PokerResource.h"
#include "PokerDefine.h"

USING_NS_CC;

typedef enum Tag_PokerActor{
    EnumPokerActorTag_BackSprite_Tag = 50,
    EnumPokerActorTag_FrontSprite_Tag = 60
}EnumPokerActorTag;

bool PokerActor::init(){
    
    if ( CCSprite::create( D_PokerResource_Back ) ) {
        
        // 初始化 Card
        m_bIsFlip = false;
        m_bIsAnimating = false;
        enumColor = EnumPokerFlowerColor_NotSet;
        enumNumber = EnumPokerNumber_NotSet;
        
        // 背面
        CCSprite *pokerBackSprite = CCSprite::create("pokers_back.png");
        pokerBackSprite->setPosition(ccp(0, 0));
        pokerBackSprite->setScaleX(1.0f);
        this->addChild(pokerBackSprite , EnumPokerActorTag_BackSprite_Tag , EnumPokerActorTag_BackSprite_Tag);
        
        // 正面
        CCSprite *pokerFrontSprite = CCSprite::create("pokers_back.png");
        pokerFrontSprite->setPosition(ccp(0, 0));
        pokerFrontSprite->setScaleX(0.0f);
        this->addChild(pokerFrontSprite , EnumPokerActorTag_FrontSprite_Tag , EnumPokerActorTag_FrontSprite_Tag);
        
//        this->setContentSize( CCSizeMake(pokerBackSprite->getContentSize().width, pokerBackSprite->getContentSize().height));
        
        return true;
    }
    return false;
}

void PokerActor::setPokerNumber( unsigned int uNumber ){
    enumColor = (EnumPokerFlowerColor)(uNumber / 13);
    enumNumber = (EnumPokerNumber)(uNumber % 13);
    m_uCardNumber = uNumber;
}

void PokerActor::setPokerCardImage( const char *sBackString , const char *sFrontString ){
    CCSprite *backSprite = (CCSprite *)this->getChildByTag(EnumPokerActorTag_BackSprite_Tag);
    backSprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(sBackString));
    
    CCSprite *frontSprite = (CCSprite *)this->getChildByTag(EnumPokerActorTag_FrontSprite_Tag);
    frontSprite->setTexture(CCTextureCache::sharedTextureCache()->addImage(sFrontString));
}

void PokerActor::setFlowerColor( EnumPokerFlowerColor enumFlowerColor ){
    enumColor = enumFlowerColor;
    m_uCardNumber = enumNumber + enumColor*13;
    // TODO: 這裡應該要做到更換圖片
}

void PokerActor::setNumber(EnumPokerNumber enumPokerNumber ){
    enumNumber = enumPokerNumber;
    m_uCardNumber = enumNumber + enumColor*13;
    // TODO: 這裡應該要做到更換圖片
}

EnumPokerFlowerColor PokerActor::getPokerFlowerColor(){
    return enumColor;
}

EnumPokerNumber PokerActor::getPokerNumber(){
    return enumNumber;
}

bool PokerActor::isOpen(){
    return m_bIsFlip;
}

void PokerActor::filp( bool bOpen){
    
    if ( m_bIsAnimating == false ) {
        if ( bOpen ) {
            if ( !m_bIsFlip ) {
                m_bIsFlip = true;
                m_bIsAnimating = true;
                
                // 翻開
                // 建立打開的 Action
                CCScaleTo *closeFrontAction = CCScaleTo::create(0.3f * D_Animation_Speed , 0, 1.0f);
                CCEaseOut *easeOutAction = CCEaseOut::create(closeFrontAction, 1.0f);
                
                // 建立關閉的 Action
                CCDelayTime *delayAction = CCDelayTime::create(0.3f * D_Animation_Speed);
                CCScaleTo *openBackAction = CCScaleTo::create(0.3f * D_Animation_Speed , 1.0f, 1.0f);
                CCEaseIn *easeInAction = CCEaseIn::create(openBackAction, 1.0f);
                CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(PokerActor::endAnimating));
                CCSequence *sequenceAction = CCSequence::create( delayAction , easeInAction, funcAction , NULL);
                
                CCSprite *backSprite = (CCSprite *)this->getChildByTag(EnumPokerActorTag_BackSprite_Tag);
                CCSprite *frontSprite = (CCSprite *)this->getChildByTag(EnumPokerActorTag_FrontSprite_Tag);
                
                backSprite->runAction(easeOutAction);
                frontSprite->runAction(sequenceAction);
                
            }
        }
        else{
            if ( m_bIsFlip ) {
                m_bIsFlip = false;
                m_bIsAnimating = true;
                
                // 關閉
                // 建立關閉的 Action
                CCScaleTo *closeBackAction = CCScaleTo::create(0.3f * D_Animation_Speed , 0, 1.0f);
                CCEaseOut *easeAction = CCEaseOut::create(closeBackAction, 1.0f);
                
                // 建立打開的 Action
                CCDelayTime *delayAction = CCDelayTime::create(0.3f * D_Animation_Speed);
                CCScaleTo *openFrontAction = CCScaleTo::create(0.3f * D_Animation_Speed , 1.0f, 1.0f);
                CCEaseIn *easeInAction = CCEaseIn::create(openFrontAction, 1.0f);
                CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(PokerActor::endAnimating));
                CCSequence *sequenceAction = CCSequence::create( delayAction , easeInAction , funcAction , NULL);
                
                
                CCSprite *frontSprite = (CCSprite *)this->getChildByTag(EnumPokerActorTag_FrontSprite_Tag);
                CCSprite *backSprite = (CCSprite *)this->getChildByTag(EnumPokerActorTag_BackSprite_Tag);
                
                frontSprite->runAction(easeAction);
                backSprite->runAction(sequenceAction);
                
            }
        }
    }
}

void PokerActor::endAnimating(){
    m_bIsAnimating = false;
}

