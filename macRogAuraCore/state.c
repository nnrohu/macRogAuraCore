#include "state.h"
#include <stdint.h>

void save_state(uint8_t brightness) {
    FILE *fp = fopen(STATE_FILE, "w");
    if (fp != NULL) {
        fprintf(fp, "%u", brightness);
        fclose(fp);
    }
}

uint8_t load_state(void) {
    FILE *fp = fopen(STATE_FILE, "r");
    if (fp != NULL) {
        unsigned int brightness;
        if (fscanf(fp, "%u", &brightness) == 1) {
            fclose(fp);
            return (uint8_t)brightness;
        }
        fclose(fp);
    }
    return 0x01; // Default brightness if file doesn't exist
}
