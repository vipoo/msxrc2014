#ifndef __FDISK
#define __FDISK

#include "msxdos.h"
#include <stdbool.h>
#include <stdlib.h>

struct _partitionState {
  bool canCreate;
  bool canDoDirectFormat;
  bool unpartitionnedSpaceInSectors;
  bool partitionsExistInDisk;
  bool canAddNow;

  uint32_t autoSizeInK;

  uint8_t partitionsCount;

  msxddosLunInfo *pLunInfo;
};

typedef struct {
  uint8_t lunCount;
  char    deviceName[MAX_INFO_LENGTH];
  uint8_t number;
} deviceInfo;

void        terminateRightPaddedString(char *string, uint8_t length);
void        composeSlotString(uint8_t slot, char *destination);
void        printSize(uint32_t sizeInK);
uint8_t     getRemainingBy1024String(uint32_t value, char *destination);
void        preparePartitionAnalysis();
uint8_t     getDiskPartitionsInfo();
const char *getDosErrorMessage(uint8_t code);

#endif