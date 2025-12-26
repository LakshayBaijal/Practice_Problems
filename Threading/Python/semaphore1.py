import asyncio

sem = asyncio.Semaphore(1)

async def f1():

    async with sem:

        print("A")
        await asyncio.sleep(2)
        print("B")

async def main():
    t1 = asyncio.create_task(f1())
    t2 = asyncio.create_task(f1())

    await t1
    await t2

asyncio.run(main())