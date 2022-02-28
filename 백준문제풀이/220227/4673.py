nums = set(range(1,10001))
generated_nums = set()

for i in nums:
    for j in str(i):
        i += int(j)
    generated_nums.add(i)

self_num = sorted(nums - generated_nums)
for i in self_num:
    print(i)
    
