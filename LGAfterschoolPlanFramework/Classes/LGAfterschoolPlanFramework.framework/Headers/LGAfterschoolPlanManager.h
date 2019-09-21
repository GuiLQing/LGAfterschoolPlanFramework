//
//  LGAfterschoolPlanManager.h
//  LGAfterschoolPlanFramework
//
//  Created by lg on 2019/7/1.
//  Copyright © 2019 lg. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

#define LGAPManager LGAfterschoolPlanManager.defaultManager
#define LGAPTrainingResGradeKey [NSString stringWithFormat:@"%@%@%@", LGAPManager.userID, LGAPManager.freeStudyBaseUrl, @"TrainResGradeKey"]
#define LGAPTrainModekey [NSString stringWithFormat:@"%@%@%@", LGAPManager.userID, LGAPManager.freeStudyBaseUrl, @"TrainModeKey"]

NS_ASSUME_NONNULL_BEGIN

@interface LGAfterschoolPlanManager : NSObject

/** 用户ID */
@property (nonatomic, copy) NSString *userID;
/** 用户名 */
@property (nonatomic, copy) NSString *userName;

@property (nonatomic, copy) NSString *globalGrade;

@property (nonatomic, copy) NSString *freeStudyBaseUrl;

@property (nonatomic, copy) NSString *englishTrainingBaseUrl;

@property (nonatomic, copy) NSString *studyLevel;

@property (nonatomic, strong, readonly) NSString *subjectCode;

@property (nonatomic, assign, readonly) NSInteger levelId;
/** trainingType 词汇听写：1， 句子听写：2， 听力选择：3 */
@property (nonatomic, copy) void (^jumpToEnglishTrainingBlock)(UIViewController *fromController, NSString *planId, NSInteger trainingType, NSString *resCode, NSNumber *lastProgress);

@property (nonatomic, copy) void (^afterschoolPlanWillDismissBlock)(void);

+ (LGAfterschoolPlanManager *)defaultManager;

- (UINavigationController *)presentAfterschoolPlanHomeViewControllerWithBackHandler:(void (^)(void))backHandler;
- (void)presentAfterschoolPlanControllerBy:(UIViewController *)controller;
- (void (^)(UIViewController *controller))presentAfterschoolPlanController;

/** 进入课外计划模块需要调用大数据推送登陆接口，要传入必要的参数 */
@property (nonatomic, copy) NSString *schoolName;   //学校名称
@property (nonatomic, copy) NSString *schoolID;     //学校ID
@property (nonatomic, copy) NSString *gradeName;    //年级名称
@property (nonatomic, copy) NSString *gradeID;      //年级ID
@property (nonatomic, copy) NSString *groupName;    //班级名称
@property (nonatomic, copy) NSString *groupID;      //班级ID
@property (nonatomic, copy) NSString *subjectName;  //学科名称
@property (nonatomic, copy) NSString *subjectID;    //学科ID
@property (nonatomic, copy) NSString *courseNO;     //课程ID
@property (nonatomic, copy) NSString *courseName;   //课程名称
@property (nonatomic, copy) NSString *token;        //用户登录令牌

@property (nonatomic, assign) NSInteger serverTimeStamp;
@property (nonatomic, assign) NSInteger timeStampLocalBegin;

/**
 跳转到课外计划详情界面

 @param studyPlanType 计划类型(1-词汇背诵，2-听力训练)
 @param planId 学习计划ID
 @param rangeId 阶段ID
 @param planState 任务状态(0-进行中，1-未开始, 2-已结束)
 @param planName 计划名称
 */
- (UINavigationController *)presentAfterschoolPlanDetailWithStudyPlanType:(NSInteger)studyPlanType planId:(NSString *)planId rangeId:(NSString *)rangeId planState:(NSInteger)planState planName:(NSString *)planName backHandler:(void (^)(void))backHandler;

- (void)presentAfterschoolPlanDetailVCBy:(UIViewController *)controller studyPlanType:(NSInteger)studyPlanType planId:(NSString *)planId rangeId:(NSString *)rangeId planState:(NSInteger)planState planName:(NSString *)planName;

@end

NS_ASSUME_NONNULL_END
