#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        long long int n, boxWidth, spaceLeft, widths;
        scanf("%lld%lld", &n, &boxWidth); // <-----width of big box----->
        multiset<int> rec;                // <-----rec means small rectangular----->

        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &widths); // <-----widths is width of small rectangular----->
            rec.insert(widths);
        }

        int height = 1;
        spaceLeft = boxWidth; // <-----initially big box is empty so the remaining space is equal to big box width----->
        while (!rec.empty())
        {
            auto it = rec.upper_bound(spaceLeft);
            if (it == rec.begin())
            {
                height++;
                spaceLeft = boxWidth; // <-----now big box is empty so the remaining space is equal to big box width----->
            }

            else // <-----iterator is pointing at rec.end()----->
            {
                it--;                        // <-----finding out the maximum width----->
                long long int val = (*it);   // <-----assigning the value of index or iterator----->
                spaceLeft = spaceLeft - val; // <-----the remaining space after setting up a small rectangle in a specific level----->
                rec.erase(it);
            }
        }
        printf("%d\n", height);
    }
}