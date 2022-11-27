#!/usr/bin/python3
"""
this program will determine wether or not a set of boxes together contain the keys to unlock all boxes
"""

def canUnlockAll(boxes):
    """Determine if all boxes can be unlocked"""
    if boxes:
        keys = [0]
        keysNeeded = [i[0] for i in enumerate(boxes)]

        #collecr keys from all unlockable boxes begining with 0
        collectKeys(boxes, keys)

        #return true or false depending on if keys present match key needed
        return sorted(keys) == keysNeeded
    else:
        return True

def collectKeys(boxes, keys, key=0):
    """ recursively collectr all unique ekys from all boxes"""
    for newKey in boxes[key]:
        if newKey not in keys and newKey < len(boxes):
            keys.append(newKey)
            collectKeys(boxes, keys, newKey)
