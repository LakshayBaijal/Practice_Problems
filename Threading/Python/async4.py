import asyncio

async def func(n):
    result = n * n
    await asyncio.sleep(1)
    return result

async def main():
    n = int(input())
    t = asyncio.create_task(func(n))

    result = await t
    print(result)

asyncio.run(main())