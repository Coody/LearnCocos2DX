//
//  BlockMoveManager.h
//  BlockGame
//
//  Created by Coody on 2016/10/3.
//
//

#ifndef BlockMoveManager_h
#define BlockMoveManager_h

#include "cocos2d.h"
#include "BlockGameConstant.h"
#include "BasicBlock.h"

class BlockMoveManager : public cocos2d::CCNode {
    
public:
    virtual bool initWithArray( cocos2d::CCArray *originalArray );
    
    static BlockMoveManager *create( cocos2d::CCArray *originalArray ){
        BlockMoveManager *pRet = new BlockMoveManager();
        if ( pRet && pRet->initWithArray( originalArray ) ) {
            pRet->autorelease();
            return pRet;
        }
        else{
            delete pRet;
            pRet = NULL;
            return NULL;
        }
    }
    
    void resetFirstArray( cocos2d::CCArray *originalArray);
    
    // 查詢是否可走？
    bool canGo( unsigned int position );
    
    // 導航走向（會選個位置，如果沒辦法走，回傳 -1 ）
    int gpsGo( unsigned int recentPoint );
    
    // 結束將 feature Dic 同步到 recent Dic
    void synchronizeDic();
    
    // 新增、移除
    void addNewBlock( BasicBlock *block );
    void removeBlock( BasicBlock *block );
    
    // 記憶體釋放
    void releaseDics();
    
#ifdef D_Dev_Ver
    void showRecent();
    void showFeature();
#endif
    
private:
    
    cocos2d::CCDictionary *m_dRecentDic;
    cocos2d::CCDictionary *m_dFutureDic;
    
};

#endif /* BlockMoveManager_h */
