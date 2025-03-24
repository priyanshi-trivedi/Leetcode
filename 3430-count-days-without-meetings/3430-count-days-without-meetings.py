class Solution:
    def countDays(self, days: int, meetings: List[List[int]]) -> int:
        meetings.sort()
        merged = []
        for start, end in meetings:
            if merged and merged[-1][1] >= start - 1:
                merged[-1][1] = max(merged[-1][1], end)
            else:
                merged.append([start, end])

        free_days = 0
        last_end = 0
        for start, end in merged:
            if start > last_end + 1:
                free_days += (start - last_end - 1)
            last_end = end

        if last_end < days:
            free_days += (days - last_end)
        return free_days    