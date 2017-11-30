//
//  NSObject+userStateVerify.m
//  lazyaudio
//
//  Created by lazy-iOS2 on 16/12/16.
//
//


#import "NSObject+LRTSUserStateVerify.h"

@implementation NSObject (LRTSUserStateVerify)

- (BOOL)isTrueOfUserStateType:(LRTSUserStateType)type {
    SEL selector = @selector(userState);
    if ([self respondsToSelector:selector]) {
        return ([self userState] & type) > 0;
    }
    return NO;
}

- (BOOL)isVIP {
    return [self isTrueOfUserStateType:LRTSUserStateTypeVIP];
}

- (BOOL)isVerifiedAnnouncer {
    return [self isTrueOfUserStateType:LRTSUserStateTypeVerifiedAnnouncer];
}

- (BOOL)isUnverifiedAnnouncer {
    return [self isTrueOfUserStateType:LRTSUserStateTypeUnverifiedAnnouncer];
}

- (void)disableUnverifiedAnnouncerFlag {
    void(^disableUnverified)(id<NSObjectUserStateVerify> obj) = ^(id<NSObjectUserStateVerify> obj){
        SEL setSelector = @selector(setUserState:);
        SEL getSelector = @selector(userState);
        if ([obj respondsToSelector:setSelector] && [obj respondsToSelector:getSelector]) {
            long long userState = [obj userState];
//TODO  注册掉
//            [obj setUserState:(userState & (LRTSUserStateTypeUnverifiedAnnouncer ^ LONG_LONG_MAX))];
        }
    };
    
    if ([self isKindOfClass:[NSArray class]]) {
        for (id object in ((NSArray *)self)) {
            disableUnverified(object);
        }
    } else {
        disableUnverified(self);
    }
}

@end

