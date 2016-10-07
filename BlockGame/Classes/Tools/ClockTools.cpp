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

#pragma mark - Public
bool ClockTools::init(){
    
    if ( CCNode::init() ) {
        
        m_fBasicTick = D_ClockTools_BasicTick;
        m_fTotalTime = 0;
        m_uiMaxTime = 9999999;
        
        CCSize fontSize = CCSizeMake(250,74);
        
#ifdef D_Test
        CCLayerColor *layer = CCLayerColor::create( D_BlockGame_BlackLayerColor , fontSize.width, fontSize.height);
        layer->setAnchorPoint( ccp(0, 0));
        this->addChild(layer);
#endif
        
        
        CCLabelTTF *timeLabel = CCLabelTTF::create("0",
                                                   D_BlockGame_FontName2,
                                                   60,
                                                   fontSize,
                                                   kCCTextAlignmentRight , kCCVerticalTextAlignmentBottom);
#ifdef D_Test
        timeLabel->setColor(ccYELLOW);
#else
        timeLabel->setColor(ccBLACK);
#endif
        timeLabel->setPosition(ccp(0, 0));
        timeLabel->setAnchorPoint(ccp(0, 0));
        this->addChild(timeLabel , EnumClockToolsTag_TimeLabel , EnumClockToolsTag_TimeLabel);
        
        
        
        this->scheduleUpdate();
        
        return true;
    }
    
    return false;
}

void ClockTools::setNumberColor( const ccColor3B& color ){
    CCLabelTTF *labelTTF = (CCLabelTTF *)this->getChildByTag( EnumClockToolsTag_TimeLabel );
    labelTTF->setColor(color);
}

void ClockTools::setNumberLayerAlpha( float alphaValue ){
    CCLabelTTF *labelTTF = (CCLabelTTF *)this->getChildByTag( EnumClockToolsTag_TimeLabel );
    labelTTF->setOpacity(alphaValue);
    
}

void ClockTools::setStartTimeAndTick(  float basicTick , unsigned int time  ){
    m_fTotalTime = time;
    if ( basicTick < 0 ) {
        basicTick = D_ClockTools_BasicTick;
    }
    m_fBasicTick = basicTick;
    CCLabelTTF *labelTTF = (CCLabelTTF *)this->getChildByTag( EnumClockToolsTag_TimeLabel );
    labelTTF->setString(CCString::createWithFormat("%d" , (int)m_fTotalTime)->getCString());
}

void ClockTools::setMaxTime( unsigned int maxTime ){
    m_uiMaxTime = maxTime;
    if ( m_fTotalTime > m_uiMaxTime ) {
        m_fTotalTime = m_uiMaxTime;
        this->stopCount();
    }
}

void ClockTools::startCount(){
    this->schedule(schedule_selector(ClockTools::calculate), m_fBasicTick );
}

void ClockTools::stopCount(){
    this->unschedule(schedule_selector(ClockTools::calculate));
}

#pragma mark - Private
void ClockTools::calculate(){
    CCLabelTTF *labelTTF = (CCLabelTTF *)this->getChildByTag( EnumClockToolsTag_TimeLabel );
    m_fTotalTime = m_fTotalTime + 1;
    labelTTF->setString( CCString::createWithFormat("%d" , (int)m_fTotalTime)->getCString() );
}

