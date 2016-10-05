//
//  ActionTools.cpp
//  BlockGame
//
//  Created by Chou Coody on 2016/10/1.
//
//

#include "ActionTools.h"

USING_NS_CC;

CCSequence *ActionTools::getHeartBitAnimation(){
    
    CCScaleTo *scaleALittleBig = CCScaleTo::create(0.05, 1.2f);
    CCEaseIn *easeInAction = CCEaseIn::create(scaleALittleBig, 0.5f);
    CCScaleTo *scaleALittleSmall = CCScaleTo::create(0.05, 1.0f);
    CCEaseOut *easeOutAction = CCEaseOut::create(scaleALittleSmall, 0.5f);
    CCDelayTime *delayALittleTime = CCDelayTime::create(0.5f);
    CCSequence *sequenceHeartBit = CCSequence::create(easeInAction , easeOutAction , delayALittleTime , NULL);
    
    return sequenceHeartBit;
}

CCSequence *ActionTools::getShowAnimation( float scaleBig , float bigRate , float scaleSmall , float smallRate ){
    CCScaleBy *scaleBigAction = CCScaleBy::create( scaleBig , bigRate );
    CCEaseIn *easeBigAction = CCEaseIn::create(scaleBigAction, 0.5f);
    
    CCScaleBy *scaleSmallAction = CCScaleBy::create( scaleSmall , smallRate );
    CCEaseOut *easeSmallAction = CCEaseOut::create(scaleSmallAction, 0.5f);
    CCSequence *sequenceAction = CCSequence::create( easeBigAction , easeSmallAction , NULL);
    return sequenceAction;
}

