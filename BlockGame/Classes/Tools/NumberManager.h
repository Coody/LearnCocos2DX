//
//  NumberManager.h
//  Test01
//
//  Created by CoodyChou on 2016/9/23.
//
//

#ifndef NumberManager_h
#define NumberManager_h

#include "cocos2d.h"

class NumberManager : public cocos2d::CCNode
{
    
public:
    
    virtual bool init( const char *pFontFileName );
    
    static NumberManager *create( const char *pFontFileName )
    {
        NumberManager *pRet = new NumberManager();
        if ( pRet && pRet->init( pFontFileName ) ) {
            pRet->autorelease();
            return pRet;
        }
        else{
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
    // 設定起始跟結束分數
    void setRandomNumber( unsigned int startNumber , unsigned int endNumber );
    
    // 得到分數
    void getJumpNumbers( unsigned int uNumbers );
    void getJumpNumbers( unsigned int uNumbers , cocos2d::CCPoint moveByPoint);
    
private:
    
    const char *m_pFontFileName;
    
    // 結束 call back
    void scaleJumpNumbers(CCObject *pSender);
    
};

#endif /* NumberManager_h */
