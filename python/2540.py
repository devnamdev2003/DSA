class Solution(object):
    def getCommon(self, nums1, nums2):
        nums1 = list(set(nums1))
        nums2 = list(set(nums2))
        nums1.extend(nums2)
        nums1.sort()
        for val in range(len(nums1)-1):
            if nums1[val] == nums1[val+1]:
                return nums1[val]
        return -1
