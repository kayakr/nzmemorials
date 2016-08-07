# The Sorrow and the Pride


Our heritage, the places and people where we come from, are an important part of the culture of Aotearoa New Zealand. In towns small and large around the country, memorials stand to commemorate the fallen who served in the New Zealand Wars, World War I and World War 2. Wouldn't it be good to be able to stand in front of a monument, and see more than just names?

The New Zealand [Memorials Register](http://www.nzhistory.net.nz/culture/the-memorials-register) contains locations and photos for over a thousand war memorials across the country. In order to help people today to connect the names on those memorials with the people who lived and served before them, we want to connect this information with personnel records from the [Online Cenotaph database](http://www.aucklandmuseum.com/war-memorial/online-cenotaph).

In order to make those connections, we are setting up a website to import data for each memorial, and use crowdsourcing to transcribe and classify the text from those images. We hope that this will become a useful tool for New Zealanders who want to research their local history, and find out more about their families and [whakapapa](http://www.teara.govt.nz/en/whakapapa-genealogy/page-1).

If we can help families and historians to successfully match up these names with the people they commemorate, it could help New Zealanders to engage with and learn about our shared past through telling their personal stories. It could also become a useful resource for visitors to the country, helping them to understand the history and culture of the people who live here.

## Project Name
"The Sorrow And The Pride" is an homage to [The Sorrow And The Pride: New Zealand War Memorials](https://www.amazon.com/sorrow-pride-New-Zealand-memorials/dp/0477014755) by Chris Maclean and Jock Philips (1990).

## Data

### Memorial
* Name
* Id: field_id, remote node id from NZHistory.
* Coordinates: field_coordinates, lat,lon.
* URL: field url, link to original page on nzhistory.net.nz.
* Image: field_images, internal reference to 0..N Image files.

### Image
* fid, local file id
* filename, e.g. lyttelton-memorial-5.jpg
* Readable text: field_readable_text, status tracking for whether image contains useful text; N/A (or _none), Yes, No.
* Inscription: field_inscription, Text area to hold raw transcription of plaque
* Transcription complete: field_transcription_status, N/A (or _none), transcribe_names_yes, transcribe_names_no.
* Names: field_names, Text area to hold text of names, but not non-name text (e.g. "Lest we forget.")
* Extract names complete: field_extract_names_complete, boolean: yes or no.
* Names (individual): field_names_individual, multiple-value field based on field_names split at new line.

### Person
* Name
* URL: link to cenotaph database.

In hindsight, (and perhaps a todo), status fields should be harmonised/merged.

## Tasks

### Task: Readable text (/task/readable-text)
Check photos for readable text.
Include all Images (file type==image) where field_readable_text != Yes,No.

### Task: Transcribe text (/task/transcribe)
Transcribe text from photos.
Include all Images where Readable text=Yes and Transcription complete != transcribe_names_yes,transcribe_names_no.

