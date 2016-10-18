//
//  ActionTools.cpp
//  BlockGame
//
//  Created by Chou Coody on 2016/10/1.
//
//

#include "ActionTools.h"

USING_NS_CC;

#pragma mark - Public
CCSequence *ActionTools::getHeartBitAnimation()
{
    
    CCScaleTo *scaleALittleBig = CCScaleTo::create( 0.05 , 1.2f * D_BlockGame_ActionTools_HeartBeatSpeed );
    CCEaseIn *easeInAction = CCEaseIn::create( scaleALittleBig , 0.5f * D_BlockGame_ActionTools_HeartBeatSpeed );
    CCScaleTo *scaleALittleSmall = CCScaleTo::create( 0.05 , 1.0f * D_BlockGame_ActionTools_HeartBeatSpeed );
    CCEaseOut *easeOutAction = CCEaseOut::create( scaleALittleSmall , 0.5f * D_BlockGame_ActionTools_HeartBeatSpeed );
    CCDelayTime *delayALittleTime = CCDelayTime::create( 0.5f * D_BlockGame_ActionTools_HeartBeatSpeed );
    CCSequence *sequenceHeartBit = CCSequence::create( easeInAction , easeOutAction , delayALittleTime , NULL );
    
    return sequenceHeartBit;
}

CCSequence *ActionTools::getShowAnimation(float scaleBigTime,
                                          float bigRate,
                                          float scaleSmallTime)
{
    return ActionTools::getShowAnimation(scaleBigTime, bigRate, scaleSmallTime, 1.0f);
}

/**
 *  顯示出場動畫的 Action（由正常大小 -> 變大 -> 變無 ）
 *
 *  @param scaleBigTime   變大的時間
 *  @param bigRate        變大的倍率
 *  @param scaleSmallTime 變小的時間
 */
CCSequence *ActionTools::getHideAnimation(float scaleBigTime,
                                          float bigRate,
                                          float scaleSmallTime)
{
    return ActionTools::getHideAnimation(scaleBigTime, bigRate, scaleSmallTime, 0.0f);
}

#pragma mark - Private
CCSequence *ActionTools::getShowAnimation(float scaleBigTime, 
                                          float bigRate,
                                          float scaleSmallTime,
                                          float smallRate)
{
    CCScaleBy *scaleBigAction = CCScaleBy::create( scaleBigTime , bigRate );
    CCEaseIn *easeBigAction = CCEaseIn::create(scaleBigAction, 0.5f);
    
    CCScaleBy *scaleSmallAction = CCScaleBy::create( scaleSmallTime , smallRate );
    CCEaseOut *easeSmallAction = CCEaseOut::create(scaleSmallAction, 0.5f);
    CCSequence *sequenceAction = CCSequence::create( easeBigAction , easeSmallAction , NULL);
    return sequenceAction;
}

CCSequence *ActionTools::getHideAnimation(float scaleBigTime,
                                          float bigRate,
                                          float scaleSmallTime,
                                          float smallRate)
{
    CCScaleBy *scaleBigAction = CCScaleBy::create(0.3f, 1.5f);
    CCEaseIn *easeBigAction = CCEaseIn::create(scaleBigAction, 0.7f);
    CCDelayTime *delay = CCDelayTime::create(0.15f);
    CCScaleBy *scaleSmallAction = CCScaleBy::create(0.15f, 0.0f);
    CCEaseOut *easeSmallAction = CCEaseOut::create(scaleSmallAction, 0.7f);
    
//    CCCallFunc *funcAction = CCCallFunc::create(this, callfunc_selector(StartMenuLayer::changeScene));
    
    CCSequence *sequenceAction = CCSequence::create( easeBigAction , delay , easeSmallAction  , NULL);
    return sequenceAction;
}


