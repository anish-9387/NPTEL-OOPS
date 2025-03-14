from typing import Dict, TypeVar

K=TypeVar('K')
V=TypeVar('V')

def merge_dictionaries(dict1:Dict[K,V], dict2:Dict[K,V]):
# -> Dict[K,V]
    result=dict1.copy()
    result.update(dict2)
    return result

dict_a={1:"apple", 2:"banana"}
dict_b={3:"cherry", 4:"date"}

merge_dict=merge_dictionaries(dict_a,dict_b)
print(merge_dict)