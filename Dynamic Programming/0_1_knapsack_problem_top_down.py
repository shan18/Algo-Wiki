class KnapSack:

    def __init__(self):
        self.remaining_weights = 0
        self.remaining_items = 0


def knapsack_top_down_util(values, weights, remaining_weight, total_items, current_item, item_map):
    if current_item >= total_items or remaining_weight <= 0:
        return 0
    
    knapsack = KnapSack()
    knapsack.remaining_weights = remaining_weight
    knapsack.remaining_items = total_items - current_item - 1

    if knapsack in item_map:
        return item_map[knapsack]
    
    max_value = 0
    if remaining_weight < weights[current_item]:
        max_value = knapsack_top_down_util(values, weights, remaining_weight, total_items, current_item + 1, item_map)
    else:
        max_value = max(
            values[current_item] + knapsack_top_down_util(
                values, weights, remaining_weight - weights[current_item], total_items, current_item + 1, map
            ), knapsack_top_down_util(values, weights, remaining_weight, total_items, current_item + 1, item_map)
        )
    
    item_map[knapsack] = max_value
    return max_value


def knapsack_top_down(values, weights, max_weight):
    item_map = {}
    return knapsack_top_down_util(values, weights, max_weight, len(values), 0, item_map)
