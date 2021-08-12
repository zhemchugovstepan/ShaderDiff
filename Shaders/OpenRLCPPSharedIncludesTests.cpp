#include "UnityPrefix.h"

#if ENABLE_UNIT_TESTS

#include "Runtime/Testing/Testing.h"

#include "External/Wintermute/RLSL/OpenRLCPPSharedIncludes.rlsl"

UNIT_TEST_SUITE(OpenRLCPPSharedIncludes)
{
    TEST(OpenRLCPPSharedIncludes_GetRegionIdxInsideGridReturnsValidIndex)
    {
        {
            // Check a lookup inside the grid
            const Wintermute::Vec3i region = Wintermute::Vec3i(2, 4, 11);
            const Wintermute::Vec3i gridDims = Wintermute::Vec3i(6, 8, 22);

            const int regionIdx = OpenRLCPPShared_GetRegionIdx(region, gridDims);

            CHECK_EQUAL(554, regionIdx);
        }
        {
            // Check a lookup inside the grid, but at a corner
            const Wintermute::Vec3i region = Wintermute::Vec3i(0, 0, 0);
            const Wintermute::Vec3i gridDims = Wintermute::Vec3i(1, 2, 3);

            const int regionIdx = OpenRLCPPShared_GetRegionIdx(region, gridDims);

            CHECK_EQUAL(0, regionIdx);
        }
        {
            // Check a lookup inside the grid, when there is a single cell
            const Wintermute::Vec3i region = Wintermute::Vec3i(0, 0, 0);
            const Wintermute::Vec3i gridDims = Wintermute::Vec3i(1, 1, 1);

            const int regionIdx = OpenRLCPPShared_GetRegionIdx(region, gridDims);

            CHECK_EQUAL(0, regionIdx);
        }
    }
    TEST(OpenRLCPPSharedIncludes_GetRegionIdxOutsideGridReturnsMinusOne)
    {
        {
            // Check a lookup outside the grid on X
            const Wintermute::Vec3i region = Wintermute::Vec3i(1, 1, 2);
            const Wintermute::Vec3i gridDims = Wintermute::Vec3i(1, 2, 3);

            const int regionIdx = OpenRLCPPShared_GetRegionIdx(region, gridDims);

            CHECK_EQUAL(-1, regionIdx);
        }
        {
            // Check a lookup outside the grid on Y
            const Wintermute::Vec3i region = Wintermute::Vec3i(0, 2, 2);
            const Wintermute::Vec3i gridDims = Wintermute::Vec3i(1, 2, 3);

            const int regionIdx = OpenRLCPPShared_GetRegionIdx(region, gridDims);

            CHECK_EQUAL(-1, regionIdx);
        }
        {
            // Check a lookup outside the grid on Z
            const Wintermute::Vec3i region = Wintermute::Vec3i(0, 1, 3);
            const Wintermute::Vec3i gridDims = Wintermute::Vec3i(1, 2, 3);

            const int regionIdx = OpenRLCPPShared_GetRegionIdx(region, gridDims);

            CHECK_EQUAL(-1, regionIdx);
        }
        {
            // Check a lookup outside the grid when the grid dims are zero on one dimension
            const Wintermute::Vec3i region = Wintermute::Vec3i(0, 0, 0);
            const Wintermute::Vec3i gridDims = Wintermute::Vec3i(0, 1, 1);

            const int regionIdx = OpenRLCPPShared_GetRegionIdx(region, gridDims);

            CHECK_EQUAL(-1, regionIdx);
        }
        {
            // Check a lookup outside the grid when the grid dims are negative on one dimension
            const Wintermute::Vec3i region = Wintermute::Vec3i(0, 0, 0);
            const Wintermute::Vec3i gridDims = Wintermute::Vec3i(-1, 1, 1);

            const int regionIdx = OpenRLCPPShared_GetRegionIdx(region, gridDims);

            CHECK_EQUAL(-1, regionIdx);
        }
        {
            // Check a lookup outside the grid when the grid is empty (all axes)
            const Wintermute::Vec3i region = Wintermute::Vec3i(0, 0, 0);
            const Wintermute::Vec3i gridDims = Wintermute::Vec3i(0, 0, 0);

            const int regionIdx = OpenRLCPPShared_GetRegionIdx(region, gridDims);

            CHECK_EQUAL(-1, regionIdx);
        }
        {
            // Check a lookup outside the grid when the region is negative on one axis
            const Wintermute::Vec3i region = Wintermute::Vec3i(1, 1, -1);
            const Wintermute::Vec3i gridDims = Wintermute::Vec3i(4, 4, 4);

            const int regionIdx = OpenRLCPPShared_GetRegionIdx(region, gridDims);

            CHECK_EQUAL(-1, regionIdx);
        }
    }
}


#endif // ENABLE_UNIT_TESTS
