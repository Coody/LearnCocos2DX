//
//  Npc.cpp
//  Test01
//
//  Created by Coody on 2016/9/21.
//
//

#include "Npc.h"

// for Constant
#include "NpcConstant.h"

USING_NS_CC;

typedef enum{
    EnumNPCTag_DownArray = 10,
    EnumNPCTag_LeftArray = 20,
    EnumNPCTag_RightArray = 30,
    EnumNPCTag_UpArray = 40,
    EnumNPCTag_AnimationSprite = 100
}EnumNPCTag;

#pragma mark - 開放方法
bool Npc::init( const char *cacheImageName , const char *cachePlistName ){
    
    if ( CCNode::init() ) {
        
        m_bIsArriveTarget = true;
        
        // 設定 cache name ( *.png , *.plist )
        this->setNpcImageCacheName( cachePlistName , cacheImageName);
        
        // 建立動畫的精靈
        CCString *firstFileName = CCString::createWithFormat( "%s_0001.png" , cacheImageName );
        CCSprite *animationSprite = CCSprite::createWithSpriteFrameName( firstFileName->getCString() );
        this->addChild(animationSprite , EnumNPCTag_AnimationSprite , EnumNPCTag_AnimationSprite );
        
        return true;
    }
    
    return false;
    
}


void Npc::goToPoint( cocos2d::CCPoint tempPoint ){
    
    if ( m_bIsArriveTarget == true ) {
        m_bIsArriveTarget = false;
        movePoint.x = tempPoint.x - this->getPositionX();
        movePoint.y = tempPoint.y - this->getPositionY();
        
        if( movePoint.y > 0 ){
            this->goUp();
        }
        else if( movePoint.y < 0 ){
            this->goDown();
        }
        else if ( movePoint.x > 0 ) {
            this->goRight();
        }
        else if( movePoint.x < 0 ){
            this->goLeft();
        }
        else{
            m_bIsArriveTarget = true;
        }
    }
    
}

// 往上走
void Npc::goUp(){
    
    float tempUpDistance = ( movePoint.y >= 0 ? movePoint.y : movePoint.y*-1 );
    movePoint.y = 0;
    
    // 計算動畫時間
    float animationTime = 0.5f * (tempUpDistance*0.1) * D_Animation_Speed;
    
    // 播放動畫
    CCSprite *animationSprite = (CCSprite *)this->getChildByTag( EnumNPCTag_AnimationSprite );
    CCRepeatForever *repeatAnimation = CCRepeatForever::create(CCAnimate::create(m_upAnimation));
    CCMoveBy *moveBy = CCMoveBy::create( animationTime , CCPointMake( 0 , tempUpDistance ));
    animationSprite->runAction(repeatAnimation);
    animationSprite->runAction(moveBy);
    
    // 關閉動畫
    CCDelayTime *delayTime = CCDelayTime::create(animationTime);
    CCCallFunc *funcAction = CCCallFunc::create( this , callfunc_selector( Npc::stopAnimation ));
    CCSequence *sequenceAction = CCSequence::createWithTwoActions(delayTime, funcAction);
    animationSprite->runAction(sequenceAction);
}

// 往下走
void Npc::goDown(){
    
    float tempDownDistance = ( movePoint.y >= 0 ? movePoint.y : movePoint.y*-1 );
    movePoint.y = 0;
    
    // 計算動畫時間
    float animationTime = 0.5f * (tempDownDistance*0.1) * D_Animation_Speed;
    
    // 播放動畫
    CCSprite *animationSprite = (CCSprite *)this->getChildByTag( EnumNPCTag_AnimationSprite );
    CCRepeatForever *repeatAnimation = CCRepeatForever::create(CCAnimate::create(m_downAnimation));
    CCMoveBy *moveBy = CCMoveBy::create( animationTime , CCPointMake( 0 , tempDownDistance*-1 ));
    animationSprite->runAction(repeatAnimation);
    animationSprite->runAction(moveBy);
    
    // 關閉動畫
    CCDelayTime *delayTime = CCDelayTime::create(animationTime);
    CCCallFunc *funcAction = CCCallFunc::create( this , callfunc_selector( Npc::stopAnimation ));
    CCSequence *sequenceAction = CCSequence::createWithTwoActions(delayTime, funcAction);
    animationSprite->runAction(sequenceAction);
    
}

// 往左走
void Npc::goLeft(){
    float tempLeftDistance = ( movePoint.x >= 0 ? movePoint.x : movePoint.x*-1 );
    movePoint.x = 0;
    
    // 計算動畫時間
    float animationTime = 0.5f * (tempLeftDistance*0.1) * D_Animation_Speed;
    
    // 播放動畫
    CCSprite *animationSprite = (CCSprite *)this->getChildByTag( EnumNPCTag_AnimationSprite );
    CCRepeatForever *repeatAnimation = CCRepeatForever::create(CCAnimate::create(m_leftAnimation));
    CCMoveBy *moveBy = CCMoveBy::create( animationTime , CCPointMake( tempLeftDistance*-1 , 0 ));
    animationSprite->runAction(repeatAnimation);
    animationSprite->runAction(moveBy);
    
    // 關閉動畫
    CCDelayTime *delayTime = CCDelayTime::create(animationTime);
    CCCallFunc *funcAction = CCCallFunc::create( this , callfunc_selector( Npc::stopAnimation ));
    CCSequence *sequenceAction = CCSequence::createWithTwoActions(delayTime, funcAction);
    animationSprite->runAction(sequenceAction);
}

// 往右走
void Npc::goRight(){
    float tempRightDistance = ( movePoint.x >= 0 ? movePoint.x : movePoint.x*-1 );
    movePoint.x = 0;
    
    // 計算動畫時間
    float animationTime = 0.5f * (tempRightDistance*0.1) * D_Animation_Speed;
    
    // 播放動畫
    CCSprite *animationSprite = (CCSprite *)this->getChildByTag( EnumNPCTag_AnimationSprite );
    CCRepeatForever *repeatAnimation = CCRepeatForever::create(CCAnimate::create(m_rightAnimation));
    CCMoveBy *moveBy = CCMoveBy::create( animationTime , CCPointMake( tempRightDistance , 0 ));
    animationSprite->runAction(repeatAnimation);
    animationSprite->runAction(moveBy);
    
    // 關閉動畫
    CCDelayTime *delayTime = CCDelayTime::create(animationTime);
    CCCallFunc *funcAction = CCCallFunc::create( this , callfunc_selector( Npc::stopAnimation ));
    CCSequence *sequenceAction = CCSequence::createWithTwoActions(delayTime, funcAction);
    animationSprite->runAction(sequenceAction);
}

void Npc::stopAnimation(){
    CCSprite *animationSprite = (CCSprite *)this->getChildByTag( EnumNPCTag_AnimationSprite );
    animationSprite->stopAllActions();
    
    if ( movePoint.x != 0 ) {
        if ( movePoint.x > 0 ) {
            this->goRight();
        }
        else{
            this->goLeft();
        }
    }
    else if( movePoint.y != 0 ){
        if ( movePoint.y > 0 ) {
            this->goUp();
        }
        else{
            this->goDown();
        }
    }
    else{
        m_bIsArriveTarget = true;
    }
    
}

#pragma mark - Private
void Npc::setNpcImageCacheName( const char *cachePlistName , const char *cacheImageName ){
    // 記住名稱等等要用到
    m_sPlistString = CCString::createWithFormat( "%s.plist" , cachePlistName );
    m_sImageString = CCString::createWithFormat( "%s.png" , cacheImageName );
    
    CCSpriteFrameCache *cache = CCSpriteFrameCache::sharedSpriteFrameCache();
    cache->addSpriteFramesWithFile( m_sPlistString->getCString() , m_sImageString->getCString() );
    
    // 順序為：下、左、右、上
    
    int i = 1;
    
    // 下
    CCArray *downArray = CCArray::createWithCapacity(4);
    for ( ; i <= 4 ; i++ ) {
        CCString *frameName = CCString::createWithFormat( "%s_%04d.png" , cacheImageName , i );
        CCLOG(" %s " , frameName->getCString());
        CCSpriteFrame *spriteFrame = cache->spriteFrameByName( frameName->getCString() );
        downArray->addObject(spriteFrame);
    }
    m_downAnimation = CCAnimation::createWithSpriteFrames(downArray , D_Animation_DelayTime);
    m_downAnimation->retain();
    
    // 左
    CCArray *leftArray = CCArray::createWithCapacity(4);
    for ( ; i <= 8 ; i++ ) {
        CCString *frameName = CCString::createWithFormat( "%s_%04d.png" , cacheImageName , i );
        CCLOG(" %s " , frameName->getCString());
        CCSpriteFrame *spriteFrame = cache->spriteFrameByName( frameName->getCString() );
        leftArray->addObject(spriteFrame);
    }
    m_leftAnimation = CCAnimation::createWithSpriteFrames(leftArray , D_Animation_DelayTime);
    m_leftAnimation->retain();
    
    // 右
    CCArray *rightArray = CCArray::createWithCapacity(4);
    for ( ; i <= 12 ; i++ ) {
        CCString *frameName = CCString::createWithFormat( "%s_%04d.png" , cacheImageName , i );
        CCLOG(" %s " , frameName->getCString());
        CCSpriteFrame *spriteFrame = cache->spriteFrameByName( frameName->getCString() );
        rightArray->addObject(spriteFrame);
    }
    m_rightAnimation = CCAnimation::createWithSpriteFrames(rightArray , D_Animation_DelayTime);
    m_rightAnimation->retain();
    
    // 上
    CCArray *upArray = CCArray::createWithCapacity(4);
    for ( ; i <= 16 ; i++ ) {
        CCString *frameName = CCString::createWithFormat( "%s_%04d.png" , cacheImageName , i );
        CCLOG(" %s " , frameName->getCString());
        CCSpriteFrame *spriteFrame = cache->spriteFrameByName( frameName->getCString() );
        upArray->addObject(spriteFrame);
    }
    m_upAnimation = CCAnimation::createWithSpriteFrames(upArray , D_Animation_DelayTime);
    m_upAnimation->retain();
    
}

