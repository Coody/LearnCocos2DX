//
//  JPNumberManager.h
//  Test01
//
//  Created by Coody on 2016/9/26.
//
//

#ifndef JPNumberManager_h
#define JPNumberManager_h

#include "cocos2d.h"

class JPNumberManager : public cocos2d::CCNode
{
public:
    
    virtual bool init();
    
    static JPNumberManager *create()
    {
        JPNumberManager *pRet = new JPNumberManager();
        
        if( pRet && pRet->init() ){
            pRet->autorelease();
            return pRet;
        }
        else{
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
    void startRunJPAnimation();
    void stopRunJPAnimation();
    
    // 直接設定 JP Number
    void setJPNumber( float jpNumber );
    
    // 增加 JP (會動畫顯示)
    void addJPNumber( float jpNumber );
    
    // 設定增加等差級數
    void setArithmeticNumber( float tempArithmeticNumber );
    
    // 增加跳動速度
    void setAnimationSpeed( float tempSpeed );
    
private:
    
    void actionToTargetNumber();
    
    float m_fTimeScale;
    float m_fRecentFloatNumber;
    float m_fTargetFloatNumber;
    float m_fArithmeticNumber;
};

#endif /* JPNumberManager_hpp */
