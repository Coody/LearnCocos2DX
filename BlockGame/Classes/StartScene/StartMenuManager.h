//
//  StartMenuManager.h
//  BlockGame
//
//  Created by Coody on 2016/10/17.
//
//

#ifndef StartMenuManager_h
#define StartMenuManager_h

#include "cocos2d.h"

class StartMenuManager final : public cocos2d::CCLayerColor{
    
public:
    StartMenuManager();
    virtual ~StartMenuManager();
    
    virtual bool init();
    
    CREATE_FUNC( StartMenuManager ) ;
    
    void startTitleHeartBeat();
    
private:
    
    typedef enum{
        EnumStartMenuManagerTag_Title = 10,
        EnumStartMenuManagerTag_GameBoard = 20,
        EnumStartMenuManagerTag_MenuButton = 30
    }EnumStartMenuManagerTag;
    
    void initialTitle();
    void initialBackground();
    void initialMenuButton();
    
    void selectedMenuButton();
    void changeScene();
    
#pragma mark - Sound
    // Sound
    void preloadSounds();
    void playHeartBeatSound();
    void playHeartBeatSound2();
    void playHeartBeatSound3();
    void playBGMusic();
    void playButtonPressed();
    
    unsigned int m_uiSoundPlayCount;
    bool isStartBgMusic;
    
};

#endif /* StartMenuManager_hpp */
