/**
 * @brief   TODO
 *
 * TODO
 *
 * @author  Michael Zapf <michael.zapf@fau.de>
 * @file
 */


#ifndef COWCONFIG_H
#define COWCONFIG_H

#include <string.h>
#include <stdint.h>
#include <stdio.h>
#define COWCONFIG_COUNT     (4)

typedef enum cowconfig_operation {
    OP_NO              = 0,    ///< @brief this cowconfig_rule does nothing / empty
    OP_ANY             = 1,    ///< @brief any packet with given ID triggers
    OP_LT              = 2,    ///< @brief less than
    OP_LTE             = 3,    ///< @brief less than or equal
    OP_GTE             = 4,    ///< @brief greater than or equal
    OP_GT              = 5,    ///< @brief greater than
    OP_EQ              = 6,    ///< @brief equal
    OP_NEQ             = 7,    ///< @brief not equal
    OP_RANGE_GT_LT     = 8,    ///< @brief range without borders/limits (a  <   x  <   y)
    OP_RANGE_GTE_LTE   = 9,    ///< @brief range with borders/limits    (a  <=  x  <=  b)
    OP_RANGE_GTE_LT    = 10,   ///< @brief range with left border       (a  <=  x  <=  b)
    OP_RANGE_GT_LTE    = 11,   ///< @brief range with right border      (a  <   x  <=  y)
    OP_NOT_RANGE_GT_LT   = 12, ///< @brief complementary to OP_RANGE_GT_LT
    OP_NOT_RANGE_GTE_LTE = 13, ///< @brief complementary to OP_RANGE_GTE_LTE
    OP_NOT_RANGE_GTE_LT  = 14, ///< @brief complementary to OP_RANGE_GTE_LT
    OP_NOT_RANGE_GT_LTE  = 15  ///< @brief complementary to OP_RANGE_GT_LTE
} cowconfig_operation;

typedef enum cowconfig_packet_method {
    CCPM_LIST          = 0,    ///< @brief list all rules of node
    CCPM_ADD           = 1,    ///< @brief add new rule
    CCPM_DELETE_ALL    = 2,    ///< @brief delete all rules
    CCPM_DELETE_ONE    = 3,    ///< @brief delete rule with specific id
    CCPM_DELETE_ADDR   = 4,    ///< @brief delete all rules with specific source address
    CCPM_ANSWER_LIST   = 5     ///< @brief answer to CCPM_LIST command
} cowconfig_packet_method;


/// @brief  Format of a configuration rule.
typedef struct cowconfig_rule {
    uint16_t    address;       ///< @brief source address of packets that should trigger
    uint8_t     operation;     ///< @brief operation that triggers (see \ref cowconfig_operation)
    uint8_t     action;        ///< @brief local action to be triggered (defined by node)
    uint16_t    threshold_a;   ///< @brief lower threshold value that should trigger
    uint16_t    threshold_b;   ///< @brief upper threshold value that should trigger
} cowconfig_rule;


/// @brief  Format of a packet that contains configuration data/instructions.
typedef struct cowconfig_packet {
    /// @brief local unique id for this rule
    uint8_t id;
    /// @brief method that this packet should trigger (see \ref cowconfig_packet_method)
    uint8_t method;

    union {
        /// @brief raw data
        unsigned char   raw[sizeof(cowconfig_rule)];
        /// @brief cowconfig_rule formatted data (see \ref cowconfig_rule)
        cowconfig_rule  rule;
    };
} cowconfig_packet;


/**
 * @brief local in-memory representation of configuration rules of this node
 *
 * @note    Must be defined somewhere in c code!
 */
extern cowconfig_rule cowconfig_data[COWCONFIG_COUNT];


static inline void cowconfig_init(void) {
    // should be redundant, but noone knows which bugs will occure in compilers...
    memset(cowconfig_data, 0, sizeof(cowconfig_rule) * COWCONFIG_COUNT);
}


/**
 * @brief           Adds a rule to this node.
 * @param   rule    The rule that should be added.
 */
static inline int cowconfig_add(cowconfig_rule* rule) {
    // TODO first check if rule is already added (duplicate packet)

    for (int i = 0; i < COWCONFIG_COUNT; ++i) {
        if (cowconfig_data[i].operation == OP_NO) {
            // slot is empty, use it and return index
            cowconfig_data[i].address       = rule->address;
            cowconfig_data[i].operation     = rule->operation;
            cowconfig_data[i].action        = rule->action;
            cowconfig_data[i].threshold_a   = rule->threshold_a;
            cowconfig_data[i].threshold_b   = rule->threshold_b;
#ifdef COWCONFIG_DEBUG
            printf("add rule: id: %d, address: %d, op: %d, th_a: %d, th_b: %d, ac: %d\n",
                    i, rule->address, rule->operation, rule->threshold_a,
                    rule->threshold_b, rule->action);
#endif
            return i;
        }
    }

    // no space left for configuration items
    return -1;
}


/// @brief  Deletes all rules.
static inline void cowconfig_delete_all(void) {
    cowconfig_init(); // does memset(0)
}


/**
 * @brief       Deletes the given rule.
 * @param   i   The rule number to be deleted (find out with \ref CCPM_LIST).
 */
static inline void cowconfig_delete_one(int i) {
    if (i >= COWCONFIG_COUNT) return;
    memset(&(cowconfig_data[i]), 0, sizeof(cowconfig_rule));
    printf("Deleted rule #%d.\n", i);
}


/**
 * @brief           Deletes all rules that have the given address.
 * @param   addr    Cowbus address of which the rules should be deleted.
 */
static inline void cowconfig_delete_addr(int addr) {
    for (int i = 0; i < COWCONFIG_COUNT; ++i) {
        if (cowconfig_data[i].address == addr) {
            // slot is empty, use it and return index
            memset(&(cowconfig_data[i]), 0, sizeof(cowconfig_rule));
            printf("Deleted rule #%d.\n", i);
        }
    }
}


/// @brief  Writes the configuration to stdout.
static inline void cowconfig_dump(void) {
#ifdef COWCONFIG_DEBUG
    for (int i = 0; i < COWCONFIG_COUNT; ++i) {
        printf("ID:\t\t%d\n", i);
        printf("Addr:\t\t%d\n", cowconfig_data[i].address);
        printf("Op:\t\t%d\n", cowconfig_data[i].operation);
        printf("Action:\t\t%d\n", cowconfig_data[i].action);
        printf("Threshold A:\t%d\n", cowconfig_data[i].threshold_a);
        printf("Threshold B:\t%d\n", cowconfig_data[i].threshold_b);
        printf("########################################\n\n");
    }
#endif
}



#endif // COWCONFIG_H

