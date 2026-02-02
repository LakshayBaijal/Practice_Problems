import asyncio

async def fun(x):
    print(x)
    await asyncio.sleep(2)
    print(x)

async def main():
    t1 = asyncio.create_task(fun(1))
    t2 = asyncio.create_task(fun(2))
    t3 = asyncio.create_task(fun(3))

    await t1
    await t2
    await t3

asyncio.run(main())
