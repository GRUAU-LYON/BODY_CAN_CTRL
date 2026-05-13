# BODY_CAN_CTRL

> Embedded software library for CAN bus body controller integration — GRUAU LYON

---

## Description

Ce dépôt centralise l'ensemble des logiciels embarqués développés par **GRUAU LYON** pour l'intégration de boîtiers de commande CAN carrossier.  
Chaque logiciel est identifié par un **NIUC** (Numéro d'Identification Unique de Codage) qui assure la traçabilité complète du code, du prototypage jusqu'au SAV.

---

## Structure du dépôt

```
BODY_CAN_CTRL/
├── 00 - VLX/       # Véhicules légers (motos, voitures...)
├── 01 - UTL/       # Véhicules utilitaires
├── 02 - PLX/       # Véhicules lourds (camions, bus, engins...)
├── 03 - SPE/       # Véhicules spéciaux (hors catégories)
└── uSPS_CAN_4IO_C_PL_[TEMPLATE]_[TEMPLATE]/   # Template de base
```

Chaque projet de code est rangé dans la catégorie correspondant au type de véhicule cible.

---

## Système NIUC

Le **NIUC** (Numéro d'Identification Unique de Codage) est un identifiant attribué à chaque logiciel embarqué.  
Il permet :
- Une traçabilité précise pour le **SAV et la maintenance**
- Un suivi de l'avancement du **prototypage**
- Une gestion logistique des boîtiers et de leurs versions logicielles associées
- Un versionning structuré de l'ensemble des développements

### Format

```
[année]X[code marque à 2 chiffres][numérotation à 2 chiffres]N[type véhicule]
```

**Exemple :** le logiciel n°14 développé en 2026 pour Renault Trucks → `2026X0014NPL`

---

### Codes marque

| Code | Constructeur       |
|------|--------------------|
| 00   | Renault Trucks     |
| 01   | IVECO              |
| 02   | MAN                |
| 03   | Mercedes           |
| 04   | Stellantis         |
| 05   | EuroCargo          |
| 06   | VW                 |
| 07   | Renault            |
| 08   | Škoda              |
| ...  | *(liste non exhaustive)* |

---

### Types de véhicule

| Code | Catégorie | Description |
|------|-----------|-------------|
| VLX  | Véhicule léger | Motos, voitures... |
| PLX  | Poids lourd | Camions, bus, tracteurs, engins de chantier... |
| UTL  | Utilitaire | Tout véhicule utilitaire au sens législatif |
| SPE  | Spécial | Tout véhicule hors catégories ci-dessus |

---

## Matériel

Les logiciels de ce dépôt sont développés pour les boîtiers **ICCS Electronics**.  
Documentation technique disponible sur demande.

---

## Langages

![C](https://img.shields.io/badge/C-100%25-blue?style=flat-square&logo=c)

---

## Collaboration

Ce dépôt est partagé avec **ICCS Electronics** dans le cadre du développement conjoint des boîtiers de commande CAN carrossier.

---

*GRUAU LYON — Intégration boîtier de commande CAN*
