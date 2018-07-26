NZ Memorials
============

Data derived from Ministry for Culture and Heritage as CC BY-NC https://nzhistory.govt.nz/culture/the-memorials-register (specifically https://nzhistory.govt.nz/locations.kml).

See [ABOUT.md](ABOUT.md) for the rationale driving the project.

Initial work on this project was completed as part of [GovHack NZ 2016](http://govhack.org.nz/).

## Technical Details
Based on a Drupal 7.50 framework, with custom code to parse KML geographic data from the Memorials Register and fetch linked entry data from that site. On the Online Cenotaph database, queries are made through an ElasticSearch-based API, pulling in fields that are likely to help site users to identify specific people with a name query.

## Design Considerations

As the initial focus is on crowdsourcing, the site is intended initially for data entry on desktops and tablets. The site includes responsive layouts to improve usability on handheld devices, and future development may include further mobile-friendly options, such as the ability to search for the nearest monument based on a device location supplied by users.

The Cenotaph database will be moving to a linked open data approach in August of this year, rather than its current rate-limited API. When we are sure of exactly what that will entail in terms of data access, schemas and ontologies, we can work on refining our approach: improving the quality of searching and resource linking available to site users.

Demo/Homepage URL: http://thesorrowandthepride.nz/
