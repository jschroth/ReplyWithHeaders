// replyWitHeaders MailBundle - compose reply with message headers as in forwards
//    Copyright (c) 2013 Saptarshi Guha and Jason Schroth
//
//    Permission is hereby granted, free of charge, to any person obtaining
//    a copy of this software and associated documentation files (the
//    "Software"), to deal in the Software without restriction, including
//    without limitation the rights to use, copy, modify, merge, publish,
//    distribute, sublicense, and/or sell copies of the Software, and to
//    permit persons to whom the Software is furnished to do so, subject to
//    the following conditions:
//
//    The above copyright notice and this permission notice shall be
//    included in all copies or substantial portions of the Software.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    MIT License for more details.
//
//    You should have received a copy of the MIT License along with this
//    program.  If not, see <http://opensource.org/licenses/MIT>.

//
//  MailHeaderString.h
//  ReplyWithHeader
//
//  Created by Jason Schroth on 8/15/12.
//
//

#import <Foundation/Foundation.h>
#import "WebKit/WebResource.h"
#import "WebKit/WebArchive.h"
#import <objc/objc.h>
#import <objc/objc-runtime.h>
#import <objc/objc-class.h>

@interface MailHeaderString : NSObject {
    @private
    NSMutableAttributedString *headstr;
}

-(id)init;
-(id)initWithStr: (NSAttributedString *)str;
-(id)initWithBackEnd: (id)backend;

-(void)boldHeaderLabels;
-(WebArchive *)getWebArch;
-(NSMutableAttributedString *)string;

@end
