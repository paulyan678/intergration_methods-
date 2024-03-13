import numpy as np



def eval_intergral(function, upper_bound, lower_bound, num_intervals):
    """
    This function evaluates the intergral of a function using the trapezoidal rule
    """
    h = (upper_bound - lower_bound) / num_intervals
    result = 0
    for i in range(num_intervals):
        result += function(lower_bound + i * h)
    return result * h

def eval_double_intergral_constant_bounds(function, upper_bound_x, lower_bound_x, upper_bound_y, lower_bound_y, num_intervals):
    d_x = (upper_bound_x - lower_bound_x) / num_intervals
    d_y = (upper_bound_y - lower_bound_y) / num_intervals
    result = 0
    for i in range(num_intervals):
        for j in range(num_intervals):
            result += function(lower_bound_x + i * d_x, lower_bound_y + j * d_y)
    return result * d_x * d_y

def fast_eval_intergral(function, upper_bound, lower_bound, num_intervals):
    vals = np.linspace(lower_bound, upper_bound, num_intervals)
    vals = function(vals)
    return np.sum(vals) * (upper_bound - lower_bound) / num_intervals

def fast_eval_double_intergral_constant_bounds(function, upper_bound_x, lower_bound_x, upper_bound_y, lower_bound_y, num_intervals):
    vals_x = np.linspace(lower_bound_x, upper_bound_x, num_intervals)
    vals_y = np.linspace(lower_bound_y, upper_bound_y, num_intervals)
    vals_x, vals_y = np.meshgrid(vals_x, vals_y)
    vals = function(vals_x, vals_y)
    return np.sum(vals) * (upper_bound_x - lower_bound_x) * (upper_bound_y - lower_bound_y) / num_intervals**2

def mounty_carlo_intergral(function, upper_bound, lower_bound, num_samples):
    """
    This function evaluates the intergral of a function using the monty carlo method
    """
    samples = np.random.uniform(lower_bound, upper_bound, num_samples)
    return np.mean(function(samples)) * (upper_bound - lower_bound)
# print(eval_intergral(lambda x: x**2, 1, 0, 10000)) # 0.3333333333333333
# print(eval_double_intergral_constant_bounds(lambda x, y: x**2 + y**2, 1, 0, 1, 0, 1000)) # 1.3333333333333333
# print(fast_eval_intergral(lambda x: x**2, 1, 0, 1000000)) # 0.3333333333333333
# print(fast_eval_double_intergral_constant_bounds(lambda x, y: x**2 + y**2, 1, 0, 1, 0, 10000)) # 1.3333333333333333
print(mounty_carlo_intergral(lambda x: x**2, 1, 0, 10)) # 0.3333333333333333


