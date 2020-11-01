import random

def getlength(script):
	return sum((i['length'] for i in script))

def truncate(target_length, script):
	if getlength(script) > target_length:
		script = sorted(script, key=lambda k: (k['priority'], -k['length']))[:-1]
		return truncate(target_length, script)
	return sorted(script, key=lambda k: k['index'])

def as_text(script):
	return "\n".join([i['text'] for i in script])


priorities_and_sentences = [
(1, "...now... sitting comfortably in the chair"),
(2, "...with your feet still flat on the ground"),
(3, "...back straight and head up right"),
(2, "...make these adjustments now if you need to"),
(3, "... pause.............................."),
(1, "...your eyes ...still ...comfortably closed"),
(2, "...nice and relaxed...comfortable and relaxed..."),
(3, "... pause......................................."),
(1, "...now...I want you to notice...how heavy your head is starting to feel..."),
(1, "how heavy your head feels..."),
(3, "... pause......................................."),
(2, "really noticing the weight... of your head..."),
(3, "and how much more ...comfortable...it will feel when you let your neck relaxes ...and your head begins to fall forward ...into a much more comfortable"),
]

scriptlist = [{'priority': j[0], 'text': j[1], 'length': len(j[1]), 'index': i } for i, j in enumerate(priorities_and_sentences)]

print "500 characters"
print as_text(truncate(500, scriptlist))
print "\n300 characters"
print as_text(truncate(300, scriptlist))
print "\n200 characters"
print as_text(truncate(200, scriptlist))
