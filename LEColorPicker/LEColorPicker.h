//
//  LEColorPicker.h
//  LEColorPicker
//
//  Created by Luis Enrique Espinoza Severino on 10-12-12.
//  Copyright (c) 2012 Luis Espinoza. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <GLKit/GLKit.h>
#import <QuartzCore/QuartzCore.h>

#ifndef __gl_es20_h_
#warning OpenGL ES framework not found in project, or not included in precompiled header.
#endif

#ifdef LE_DEBUG
#	 define LELog(s,...) NSLog((@"[%s] " s),__func__,## __VA_ARGS__);
#else
#	 define LELog(...) /* */
#endif

@interface LEColorScheme : NSObject
@property(nonatomic,strong)UIColor *backgroundColor;
@property(nonatomic,strong)UIColor *primaryTextColor;
@property(nonatomic,strong)UIColor *secondaryTextColor;
@end

@interface LEColorPicker : NSObject
{
    //GLuint _vertexArray;
    GLuint _vertexBuffer;
    GLuint _indexBuffer;
    GLuint _colorRenderBuffer;
    GLuint _depthRenderBuffer;
    GLuint _program;
    GLuint _proccesedWidthSlot;
    GLuint _totalWidthSlot;
    GLuint _positionSlot;
    GLuint _colorSlot;
    GLuint _texCoordSlot;
    GLuint _textureUniform;
    GLuint _aTexture;
    GLuint _tolerance;
    GLuint _colorToFilter;
    UIImage *_currentImage;
    CAEAGLLayer* _eaglLayer;
    EAGLContext *_context;
    dispatch_queue_t taskQueue;
    BOOL _isWorking;
}

/**
 This class methods is allow the client to generate three colors from a specific UIImage. The complete
 block recieves as parameter a LEColorScheme wich is the object that encapsulates the output colors.
 
 @param image Input image, wich will be used to generate the three colors.
 @param completeBlock Execution block for when the task is complete.
 */
- (void)pickColorsFromImage:(UIImage*)image onComplete:(void (^)(LEColorScheme *colorScheme))completeBlock;

@end


