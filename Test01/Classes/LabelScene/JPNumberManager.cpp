//
//  JPNumberManager.cpp
//  Test01
//
//  Created by Coody on 2016/9/26.
//
//

#include "JPNumberManager.h"

// for constant
#include "LearnCocos2DConstant.h"

USING_NS_CC;

typedef enum{
    EnumJPNumberManagerTag_Atlas = 100
}EnumJPNumberManagerTag;

bool JPNumberManager::init(){
    if ( CCNode::init() ) {
        
        m_fRecentFloatNumber = 0;
        m_fTargetFloatNumber = 0;
        m_fArithmeticNumber = 9.0f;
        m_fTimeScale = 1.0f;
        
        CCLabelAtlas *atlas = CCLabelAtlas::create("0",
                                                   D_Label_Image1,
                                                   D_Label_Image1_Width,
                                                   D_Label_Image1_Height,
                                                   '+');
        atlas->setScale(2.0f);
        this->addChild(atlas , EnumJPNumberManagerTag_Atlas , EnumJPNumberManagerTag_Atlas );
        
        this->scheduleUpdate();
        
        return true;
    }
    return false;
}

void JPNumberManager::startRunJPAnimation(){
    
    this->schedule(schedule_selector(JPNumberManager::actionToTargetNumber), (float)(0.1f/m_fTimeScale));
    
}

void JPNumberManager::stopRunJPAnimation(){
    
    this->unscheduleUpdate();
    
}

// 直接設定 JP Number
void JPNumberManager::setJPNumber( float jpNumber ){
    CCLabelAtlas *atlas = (CCLabelAtlas *)this->getChildByTag(EnumJPNumberManagerTag_Atlas);
    CCString *jpNumberString = CCString::createWithFormat("%.2f" , jpNumber);
    // 轉成 float .2f 的格式
    m_fRecentFloatNumber = jpNumberString->floatValue();
    atlas->setString(jpNumberString->getCString());
}

// 增加 JP (會動畫顯示)
void JPNumberManager::addJPNumber( float jpNumber ){
    
    
    CCString *addNumber = CCString::createWithFormat("%.2f" , jpNumber);
    m_fTargetFloatNumber = m_fTargetFloatNumber + addNumber->floatValue();
    
}

// 增加跳動速度
void JPNumberManager::setAnimationSpeed( float tempSpeed ){
    m_fTimeScale = tempSpeed;
    this->stopRunJPAnimation();
    this->startRunJPAnimation();
}

void JPNumberManager::setArithmeticNumber( float tempArithmeticNumber ){
    m_fArithmeticNumber = tempArithmeticNumber;
}

void JPNumberManager::actionToTargetNumber(){
    if ( m_fTargetFloatNumber > m_fRecentFloatNumber ) {
        if ( m_fTargetFloatNumber < m_fRecentFloatNumber + m_fArithmeticNumber ) {
            m_fRecentFloatNumber = m_fTargetFloatNumber;
        }
        else{
            m_fRecentFloatNumber = m_fRecentFloatNumber + m_fArithmeticNumber;
        }
        
        this->setJPNumber(m_fRecentFloatNumber);
    }
}



