//
//  LearnCocos2DConstant.h
//  Test01
//
//  Created by Coody on 2016/9/19.
//
//

#ifndef LearnCocos2DConstant_h
#define LearnCocos2DConstant_h

#define D_Layer_WhiteColor cocos2d::ccc4(255, 255, 255, 255)
#define D_Layer_DarkGrayColor cocos2d::ccc4(0, 0, 0, 255)
#define D_Layer_Label_Font "Noto Sans CJK TC"
#define D_Layer_BlackColor ccc3(0,0,0)
#define D_Label_Image1 "num_score_board_score_w.png"
#define D_Label_Image1_Width (8)
#define D_Label_Image1_Height (14)
#define D_Label_Image2 "set.png"
#define D_Label_Image2_Width (624)
#define D_Label_image2_Height (15)
#define D_Label_Image3 "settel_g.png"
#define D_Label_Image3_Width (14)
#define D_Label_Image3_Height (19)
#define D_Label_Image4 "settel_r.png"
#define D_Label_Image4_Width (14)
#define D_Label_Image4_Height (19)

typedef enum{
    EnumMoveSpriteLayerZPosition_TitleLabel = 1,
    EnumMoveSpriteLayerZPosition_Menu = 2,
    EnumMoveSpriteLayerZPosition_StaticSprite = 100,
    EnumMoveSpriteLayerZPosition_MoveSprite = 200
}EnumMoveSpriteLayerZPosition;

typedef enum{
    EnumScrollBarLayerZPosition_ScrollBarBG = 10,
    EnumScrollBarLayerZPosition_ScrollBarUp = 20,
    EnumScrollBarLayerZPosition_ScrollBarDown = EnumScrollBarLayerZPosition_ScrollBarUp,
    EnumScrollBarLayerZPosition_ScrollBar = 50
}EnumScrollBarLayerZPosition;

#endif /* LearnCocos2DConstant_h */
