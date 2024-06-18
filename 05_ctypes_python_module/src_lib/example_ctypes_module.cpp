extern "C"
{
#if 0
}  // pacify editor
#endif

double sum_contiguous_double_array(const double *x, long n)
{
    double ret = 0;
    for (long i = 0; i < n; i++)
	ret += x[i];
    return ret;
}


} // extern "C"
