import discord
from discord.ext import commands, tasks
from Hidden import token
import random
from inputs import responses , fortunes , quo , nerd , tech , rost , bk , cmp , blurt , cf , jk , cfe , chill , cl , ur
import os
from itertools import cycle

intents = discord.Intents.default()
intents.typing = False
intents.presences = False
client = commands.Bot(command_prefix = '_', intents=intents)

status = cycle(["_help | :(",
     "with python",
     "with discord.py",
     "syntax error...",
     "with config. settings",
     "I'm so tired",
     "society is false",
     "I'm a tired bot....",
     "with sparkles"
     ])



@client.event
async def on_ready():
    change_status.start()
    print("Processing.....")
    print("|||||||||||||||")
    print("Bot has Successfully logged onto Discord...")
    print('Successfully logged in as {0.user}...'.format(client))


@tasks.loop(seconds=600)
async def change_status():
    await client.change_presence(activity=discord.Game(next(status)))

@client.event
async def on_member_join(member):
    print(f'{member} has joined the server.....')

@client.event
async def on_member_remove(member):
    print(f'{member} has left the server......')



#commands
@client.command()
async def ping(ctx):
    phrase=["I am alive...",
            "I was definitely not sleeping...",
            "I'm still here",
            "You are using a ping command? Why?",
            "You disturbed me. I was sleeping man....",
            "At your service."]
    ph=random.choice(phrase)
    await ctx.send(f'pong...! {ph}  **{round((client.latency)*100)}ms taken......**')

@client.command(aliases=["8ball","seer"])
async def magicball(ctx, * ,question):
    await ctx.send(f'*Question: {question}\nConjecture: {random.choice(responses)}')

@client.command(aliases=['future'])
async def fortune(ctx):
    await ctx.send(random.choice(fortunes))

@client.command(aliases=['phrase','wisdom'])
async def quote(ctx):
    await ctx.send(f'`{random.choice(quo)}`')

@client.command(aliases=['joke','pun','badjoke'])
async def dadjoke(ctx):
    await ctx.send(random.choice(jk))

@client.command(aliases=['smartstuff'])
async def nerdystuff(ctx):
    await ctx.send(f'```{random.choice(nerd)}```')

@client.command(aliases=['techie','hackerman','pimp'])
async def geek(ctx):
    await ctx.send(f'`{random.choice(tech)}`')

@client.command(aliases=['shame','destroy'])
async def roast(ctx, * , link):
    await ctx.send(f'{link} , {random.choice(rost)}')

@client.command(aliases=['appreciate','commend'])
async def compliment(ctx , * ,link):
    await ctx.send(f'{link} , {random.choice(cmp)}')

@client.command()
async def flirt(ctx, * ,link ):
    await ctx.send(f'{link} , {random.choice(blurt)}')

@client.command(aliases=['goodread','read'])
async def book(ctx):
    await ctx.send(f'`Here is one of my favourite books\n{random.choice(bk)}`')

@client.command(aliases=['ask_out'])
async def wannagrabacoffee(ctx,*, link):
    await ctx.send(f'{link} , Someone wants to grab a coffee with you...*wink *wink')
    await ctx.send(f'This happened....{random.choice(cf)}')
    await ctx.send(f'*not actually.')

@client.command(aliases=['brew'])
async def coffee(ctx):
    op=f'{random.choice(cfe)}'
    embed= discord.Embed(title='Coffee',description=op,color=discord.Color.red())
    embed.set_footer(text=f'Caffeiene Level-{random.choice(cl)}.{random.choice(chill)}')
    embed.set_image(url=random.choice(ur))
    await ctx.send(embed=embed)

@client.command(aliases=['talk'])
async def say(ctx , * ,something):
    await ctx.channel.purge(limit=1)
    await ctx.send(something)

@client.command(aliases=['num_game'])
async def guessing_game(ctx):
    await ctx.send("I have thought of a number between 1 and 15... Type _guess NUMBER to guess what it is.")

@client.command()
async def guess(ctx, n:int):
     for x in range(1):
        x = random.randint(1,15)
        if (n==x):
            await ctx.send(f'{n}Wow... You guessed right :slight_smile:')
        elif(n>x):
            await ctx.send(f'Your guess-{n}.{x} was my number... You guessed too high :frowning2:')
        else:
            await ctx.send(f'Your guess-{n}.{x} was my number... You guessed too low :frowning2:')

@client.command()
async def diceroll(ctx):
    await ctx.send('Rolling dice....')
    for us in range(1):
        us=random.randint(1,6)
    for ms in range(1):
        ms=random.randint(1,6)
        if(us==ms):
            await ctx.send(f'Your number-{us}\nMy number-{ms}.\n **Since we have same number...It is a tie...**')
        elif(us>ms):
            await ctx.send(f'Your number-{us}\nMy number-{ms}.\n **You won....**')
        else:
            await ctx.send(f'Your number-{us}\nMy number-{ms}.\n **You lost...**')

@client.command()
async def helpme(ctx):
    embed= discord.Embed(title='**Help....**',description="The prefix for the bot is ' _ '. Yah it's an underscore...",colour=discord.Color.purple())
    embed.set_footer(text= 'For full list of commands with complete functions do _cmds')
    embed.add_field(name='Core',value='ping, helpme, cmds, botinfo')
    embed.add_field(name='Talkback',value='say, spam',inline=False)
    embed.add_field(name='Entertainment',value='roast, flirt, compliment, geek, nerdystuff, quote, fortune, 8ball, coffee, wannagrabacoffee, book, dadjoke',inline=False)
    embed.add_field(name='Utility',value='purge, ban, kick, unban',inline=False)
    embed.add_field(name='Games',value='diceroll, guessing_game',inline=False)
    await ctx.send(embed =embed)
@client.command()
async def botinfo(ctx):
    embed=discord.Embed(title='Dynamo:tm:',description='A dynamic bot for entertainment and other purposes...\n This has been coded in Python with the discord.py module.\nCheck out my support and help server.',url='https://discord.gg/ETS9Tqn',color=discord.Color.blue())
    embed.set_footer(text='I Hope that you enjoyed the bot....:slight_smile:')
    embed.set_image(url='https://images.unsplash.com/photo-1522961832022-ccc489643b86?ixlib=rb-1.2.1&ixid=eyJhcHBfaWQiOjEyMDd9&auto=format&fit=crop&w=400&q=60')
    await ctx.send(embed = embed)

@client.command()
async def cmds(ctx):
    embed=discord.Embed(title='COMMANDS',description="Here's a list of commands along with functions....",color=discord.Color.green())
    embed.add_field(name='helpme',value='displays the command prefix and a basic list of commands...')
    embed.add_field(name='ping',value='The default check command for checking if bot is working...',inline=False)
    embed.add_field(name='cmds',value='Dislays this message containing detailed list of commands with their functions',inline=False)
    embed.add_field(name='botinfo',value='Displays info on the bot...')
    embed.add_field(name='say',value="Makes the bot say sentences that you want it to say. Alias- 'talk'. Usage- '_say <sentence/word>'")
    embed.add_field(name='spam',value="This is the spam command. It spams stuff that you want it to spam. Aliases-'shitpost','spamalot'. Usage- '_spam <No.of times you want the bot to spam> <The message that you want the bot to spam>'")
    embed.add_field(name='roast',value="This is the roast command.Go get 'em. Usage- '_roast <@member>'")
    embed.add_field(name='flirt',value="*wink *wink Wanna hit on someone?. Usage-'_flirt <@member>'")
    embed.add_field(name='compliment',value="Wanna commend and compliment someone?. Usage- '_compliment <@member>'")
    embed.add_field(name='geek',value='Prints geeky statements...Aliases= "pimp,techie"')
    embed.add_field(name='nerdystuff',value='Prints stuff for that one nerd in the chat....')
    embed.add_field(name='quote',value='Get ready for some of the best quotes ever....')
    embed.add_field(name='fortune',value='Wanna know the future? Wanna find where you end up?. Aliases="future"')
    embed.add_field(name='8ball',value='Wanna ask questions from the crystal ball?. Aliases="seer". Usage-"_8ball <Question>"')
    embed.add_field(name='coffee',value='Just try a nice cup of coffee.............')
    embed.add_field(name='wannagrabacoffe',value="Wanna ask your e-crush out? Here you go.... Usage-'_wannagrabacoffee <@member>'")
    embed.add_field(name='book',value='Wanna read a book. Here are some recommendations....')
    embed.add_field(name='dadjoke', value='Wanna hear some cringey bad jokes?')
    embed.add_field(name='diceroll', value='Rolls a dice. If you get a number higher than the bot then you win...')
    embed.add_field(name='guessing_game',value='Bot thinks of a number smaller than 15 and you have to guess that number. If you guess it correct, you win')
    embed.set_footer(text='I hope that helped......')
    await ctx.send(embed=embed)

@client.command()
async def rate(ctx, * ,target):
    for ki in range(1):
        ki = random.randint(1,10)
        if (ki>5):
            sym=':slight_smile:'
        elif(ki==5):
            sym=':nuetral_face:'
        else:
            sym=':frowning2:'
        embed=discord.Embed(title='Hmmmmmmmm',description=f'I rate {target} a {k}/10 {sym}',colour=discord.Color.pink())
        await ctx.send(embed=embed)

@client.command()
async def stab(ctx, * , victim):
    await ctx.send(f'{victim} just got stabbed....')

@client.command(aliases=['spamalot','shitpost'])
async def spam(ctx, num:int , * , text):
    while(num>0):
        await ctx.send(text)
        num-=1

@client.command()
async def better(ctx , * ,arg):
    arg1 , arg2 = arg.split('OR')
    arf=[arg1,arg2]
    await ctx.send(f'{random.choice(arf)} is definitely better.......')

@client.command()
async def worse(ctx, *,stat):
    st1 , st2 = stat.split('OR')
    sta=[st1 , st2]
    await ctx.send(f'{random.choice(sta)} is definitely the worst....')

@client.command()
async def radioactive():
    await ctx.send(f'....')

@client.command()
async def reload(ctx, extension):
    client.unload_extension(f'cogs.{extension}')
    client.load_extension(f'cogs.{extension}')
    await ctx.send('Reloading cog.....')
@client.command()
async def unload(ctx, extension):
    client.unload_extension(f'cogs.{extension}')

for filename in os.listdir('./cogs'):
    if filename.endswith('.py'):
        client.load_extension(f'cogs.{filename[: -3]}')


#server management

@client.event
async def on_command_error(ctx, error):
    if isinstance(error,commands.CommandNotFound):
        await ctx.send("Invalid command used..... ")

@client.command(aliases=['clear','delete'])
async def purge(ctx, amount:int):
    await ctx.channel.purge(limit=amount+1)
    await ctx.send(f'{amount} messages deleted. You done?')
@purge.error
async def purge_errror(ctx, error):
    if isinstance(error,commands.MissingRequiredArgument):
        await ctx.send('Specify the number of messages you want me to delete, dummy...')
@client.command()
async def kick(ctx , member:discord.Member , * ,reason= None):
    await member.kick(reason=reason)
    await ctx.send(f'{member.mention} has been kicked.\n```Reason:{reason}```')

@client.command()
async def ban(ctx , member:discord.Member , * ,reason= None):
    await member.ban(reason=reason)
    await ctx.send(f'{member.mention} has been banned.\n```Reason:{reason}```')

@client.command()
async def unban(ctx , * ,member:discord.Member):
    banned_users= await ctx.guild.bans()
    member_name , member_descriminator = member.split('#')
    for ban_entry in banned_users:
        user=ban_entry.user
        if((user.name , user.descriminator) == (member_name , member_descriminator)):
            await ctx.guild.unban(user)
            await ctx.send(f'{user.mention} has been unbanned....')
            return


client.run(token)
