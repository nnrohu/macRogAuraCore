#ifndef state_h
#define state_h

#include <stdio.h>
#include <stdint.h>

// State file path
#define STATE_FILE "/tmp/macRogAuraCore.state"

// Save current brightness to state file
void save_state(uint8_t brightness);

// Load brightness from state file
// Returns 1 if successful, 0 if file doesn't exist
uint8_t load_state(void);

#endif /* state_h */
