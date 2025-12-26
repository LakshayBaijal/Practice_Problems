import asyncio

sem = asyncio.Semaphore(1)

async def f1():
    print("A")

    async with sem:
        print("B")
        await asyncio.sleep(2)

        await f2()

async def f2():
    print("C")
    async with sem:
        print("D")
        await asyncio.sleep(2)


async def main():
    await f1()

asyncio.run(main())