class Solution:
    def maxTwoEvents(self, events: List[List[int]]) -> int:
        events.sort(key=lambda x: x[1])
        max_value = [0] * len(events)
        end_times = [event[1] for event in events]
        
        max_val = 0
        for i in range(len(events)):
            max_val = max(max_val, events[i][2])
            max_value[i] = max_val

        result = 0
        
        for i in range(len(events)):
            start, end, value = events[i]
            idx = bisect_right(end_times, start - 1) - 1
            if idx >= 0:
                result = max(result, value + max_value[idx])
            else:
                result = max(result, value)
        
        return result

        