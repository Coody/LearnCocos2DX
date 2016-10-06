//
//  ClockTools.cpp
//  BlockGame
//
//  Created by Coody on 2016/10/6.
//
//

#include "ClockTools.h"

// for Constant
#include "BlockGameConstant.h"

USING_NS_CC;

bool ClockTools::init(){
    
    if ( CCNode::init() ) {
        
        CCSize fontSize = CCSizeMake(100, 50);
        CCLabelTTF *timeLabel = CCLabelTTF::create("0",
                                                   D_BlockGame_FontName2,
                                                   40,
                                                   fontSize,
                                                   kCCTextAlignmentRight);
        timeLabel->setColor(ccBLACK);
        this->addChild(timeLabel , EnumClockToolsTag_TimeLabel , EnumClockToolsTag_TimeLabel);
        
        return true;
    }
    
    return false;
}

void ClockTools::setStartTime( unsigned int time ){
    
}

void ClockTools::startCount(){
    
}

void ClockTools::stopCount(){
    
}


