//
//  SPARQL
//
//  Created by Rflpz on 08/06/15.
//  Copyright (c) 2015 Rflpz. All rights reserved.
//



#import <Foundation/Foundation.h>
#import "AFJSONRequestOperation.h"

@interface SPARQL : NSObject {
    NSMutableArray *prefixes;
    NSMutableArray *variables;
    NSMutableArray *wheres;
    NSMutableArray *orderBys;
    NSMutableArray *unions;
    
    NSString *selectGraph;
    NSString *insertGraph;
    NSString *deleteGraph;
    NSString *deleteCondition;
}

@property (strong, nonatomic) NSString *baseUrl;
@property (strong, nonatomic) NSString *method;
@property (strong, nonatomic) NSString *queryParameterName;
@property (strong, nonatomic) NSString *formatParameterName;
@property (strong, nonatomic) NSString *formatParameterValue;
@property (nonatomic) BOOL distinct;
@property (nonatomic) int limit;
@property (nonatomic) int offset;
@property (nonatomic) BOOL debug;

- (id) initWithBaseUrl:(NSString *)url;

#pragma marks - Methods

- (void)addPrefixeWithNamespace:(NSString *)ns andURI:(NSString *)uri;

- (void)addVariableWithName:(NSString *)name;
- (void)addVariablesWithNames:(NSArray *)names;

- (void)selectInGraph:(NSString *)graph;
- (void)insertInGraph:(NSString *)graph;
- (void)deleteInGraph:(NSString *)graph withCondition:(NSString *)condition;

- (void)addWhereWithSubject:(NSString *)subject predicate:(NSString *)predicate andObject:(NSString *)object;
- (void)addOptionalWhereWithSubject:(NSString *)subject predicate:(NSString *)predicate andObject:(NSString *)object;
- (void)addComplexeOptionalWhereWithSPARQLObject:(SPARQL *)sparqlObject;

- (void)addUnionWithSPARQLObject:(SPARQL *)sparqlObject;

- (void)addFilter:(NSString *)filter;

- (void)addOrderByOnVariable:(NSString *)variable inASC:(BOOL)asc;

- (void)executeQueryWithSuccess:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, id JSON))success
                      orFailure:(void (^)(NSURLRequest *request, NSHTTPURLResponse *response, NSError *error, id JSON))failure;

- (NSString *)query;

- (NSString *)buildWhere;

@end

