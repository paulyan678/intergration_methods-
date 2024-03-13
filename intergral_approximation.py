



def eval_intergral(function, upper_bound, lower_bound, num_intervals):
    """
    This function evaluates the intergral of a function using the trapezoidal rule
    """
    h = (upper_bound - lower_bound) / num_intervals
    result = 0
    for i in range(num_intervals):
        result += function(lower_bound + i * h)
    return result * h

print(eval_intergral(lambda x: x**2, 1, 0, 10000000)) # 0.3333333333333333